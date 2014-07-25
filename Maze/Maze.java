import java.awt.*;

public class Maze
{
	public int SIZE = 20; //should probably be 20.
	private boolean EWWalls[][], NSWalls[][];
	private int walls;
	private final int NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3;
	private Point solution[];
	private int solutionLength;
	public boolean fastMaze = true;
	public boolean fastSolution = true;

	//need to know how to paint solution, he said it's pretty simple with the arrays.

	public Maze()//SIZE will probably be put in as a parameter.
	{

		clearMaze();
	}

	public void clearMaze()
	{
		EWWalls = new boolean[SIZE+1][SIZE+1];
		NSWalls = new boolean[SIZE+1][SIZE+1];
		solution = new Point[SIZE*SIZE];
		solutionLength = 0;
		for(int x = 0; x <=SIZE;x++)
					for(int y = 0; y<=SIZE; y++)
						EWWalls[x][y] = NSWalls[x][y] = false;
				for(int x = 0; x < SIZE; x++)
					EWWalls[x][0]= EWWalls[x][SIZE]=NSWalls[0][x]=NSWalls[SIZE][x]=true;
		NSWalls[0][0] = NSWalls[SIZE][SIZE-1]=false;
	}

	public void paint(Graphics g)
	{
		g.setColor(Color.black);
		g.drawString("Solution Length: " + solutionLength, 290, 190);
		for(int x = 0; x<=SIZE; x++)
		{
			for(int y = 0; y <= SIZE; y++)
			{
				if(!fastMaze){
					try{
						Thread.currentThread().sleep(50);
					}catch(Exception e){}
				}

				if(EWWalls[x][y])
					g.drawLine(10+10*x, 10+10*y, 10+10*(x+1), 10+10*y);
				if(NSWalls[x][y])
					g.drawLine(10+10*x, 10+10*y, 10+10*x, 10+10*(y+1));
			}
		}
		g.setColor(Color.red);
		System.out.println(solutionLength);
		for(int i = 0; i < solutionLength-1; i++)
		{
			if(!fastSolution){
				try{
					Thread.currentThread().sleep(100);
				}catch(Exception e){}
			}
			g.drawLine((int)solution[i].getX()*10+15, (int)solution[i].getY()*10+15, (int)solution[i+1].getX()*10+15, (int)solution[i+1].getY()*10+15);
		}
		g.setColor(Color.black);


	}

	private int drawLine(int x, int y, int dir)
	{
		if(dir == NORTH)
		{
			if(connected(x,y-1))
			{
				int yy = y-1;
				int made = 0;
				while(!connected(x,yy+1))
				{
					NSWalls[x][yy] = true;
					made++; yy++;
				}
				return made;
			}
		}

		if(dir == SOUTH)
		{
			if(connected(x,y+1))
			{
				int yy = y;
				int made = 0;
				while(!connected(x,yy-1))
				{
					NSWalls[x][yy] = true;
					made++; yy--;
				}
				return made;
			}
		}

		if(dir == EAST)
		{
			if(connected(x-1,y))
			{
				int xx = x-1;
				int made = 0;
				while(!connected(xx+1,y))
				{
					EWWalls[xx][y] = true;
					made++; xx++;
				}
				return made;
			}
		}

		if(dir == WEST)
		{
			if(connected(x+1,y))
			{
				int xx = x;
				int made = 0;
				while(!connected(xx-1,y))
				{
					EWWalls[xx][y] = true;
					made++; xx--;
				}
				return made;
			}
		}
		return 0;
	}

	public void fillMaze()
	{
		clearMaze();
		int dotsToGo = (SIZE-1)*(SIZE-1);
		while(dotsToGo > 0)//eventually change 70 to 0
		{
			int x = 1+(int)((SIZE-1)*Math.random());
			int y = (int)((SIZE-1)*Math.random())+1;
			int dir = (int)(4*Math.random());
			if(!connected(x,y))
			{
				dotsToGo -= drawLine(x,y,dir);
			}
		}
	}

	private boolean connected(int x, int y)
	{
		if(EWWalls[x][y]) return true;
		if(NSWalls[x][y]) return true;
		if(EWWalls[x-1][y]) return true;
		if(NSWalls[x][y-1]) return true;
		return false;
	}

	public void findSolution()
	{
		solutionLength = 2;
		solution[0] = new Point(-1,0);
		solution[1] = new Point(0,0);
		try
		{
			growSolution();
		}
		catch(FoundSolutionException e)
		{
			return;
		}
		System.out.println("Yuk! No solution found!");

	}

	private void growSolution() throws FoundSolutionException
	{
		int x = solution[solutionLength-1].x, y = solution[solutionLength-1].y;
		if(x == SIZE && y == SIZE-1)
			throw new FoundSolutionException();
		if(!NSWalls[x+1][y] && !solution[solutionLength-2].equals(new Point(x+1, y)))
		{
			solution[solutionLength++] = new Point(x+1, y);
			growSolution();
			solutionLength--;
		}
		if(!EWWalls[x][y+1] && !solution[solutionLength-2].equals(new Point(x, y+1)))
		{
			solution[solutionLength++] = new Point(x, y+1);
			growSolution();
			solutionLength--;
		}
		if(!NSWalls[x][y] && !solution[solutionLength-2].equals(new Point(x-1, y)))
		{
			solution[solutionLength++] = new Point(x-1, y);
			growSolution();
			solutionLength--;
		}
		if(!EWWalls[x][y] && !solution[solutionLength-2].equals(new Point(x, y-1)))
		{
			solution[solutionLength++] = new Point(x, y-1);
			growSolution();
			solutionLength--;
		}
	}
}

class FoundSolutionException extends Exception
{
}