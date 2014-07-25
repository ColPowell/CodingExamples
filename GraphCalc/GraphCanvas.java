import java.awt.*;

public class GraphCanvas extends Canvas
	{
	private Function f;
	private double xLow, xHigh, yLow, yHigh;
	private double xShift, xRatio, yShift, yRatio;
	
	public GraphCanvas(Function theFunction)
		{
		xLow = -6;
		xHigh = 6;
		yLow = -4;
		yHigh = 4;
		f = theFunction;
		}
	
	public void paint(Graphics g)
		{
		plotAxes(g);
		plotGraph(g);
		}
		
	public void setCoordinates(double xl, double xh, double yl, double yh)
		{
		xLow = xl;
		xHigh = xh;
		yLow = yl;
		yHigh = yh;
		}
		
	private void setShifts()
		{
		xRatio = getSize().width/(xHigh-xLow);
		xShift = -xLow * xRatio;
		yRatio = getSize().height/(yHigh-yLow);
		yShift = -yLow * yRatio;
		}
		
	private void plotLine(Graphics g, double x1, double y1, double x2, double y2)
		{
		int lowPixel = getSize().height;
		g.drawLine((int)(x1*xRatio + xShift), lowPixel-(int)(y1*yRatio + yShift),
						(int)(x2*xRatio + xShift), lowPixel-(int)(y2*yRatio + yShift));
		}
	
	public void plotAxes(Graphics g)
		{
		setShifts();	// canvas size is changable!
		g.setColor(Color.gray);
		plotLine(g, 0, yLow, 0, yHigh);
		plotLine(g, xLow, 0, xHigh, 0);		
		}
	
	private void plotGraph(Graphics g)
		{
		setShifts();	// canvas size is changable!
		g.setColor(Color.black);
		double x = xLow;
		double dx = (xHigh-xLow)/(getSize().width - 1);
		double y = f.getValue(xLow);
		x += dx;
		double y2 = f.getValue(xLow);
		for (int n=1; n<getSize().width; n++)
			{
			plotLine(g, x-dx, y, x, y2);
			y = y2;
			x += dx;
			y2 = f.getValue(x);
			}
		}
	}