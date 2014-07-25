import java.awt.*;
import java.awt.event.*;

public class MyPanel3 extends Panel implements ActionListener
	{
	private static final Font SMALL_FONT = new Font("SansSerif", Font.PLAIN, 12);
	private Label infixLabel, postfixLabel;
	private TextField infix, postfix;
	private Button showHide;
	private GraphCanvas graph;
	private Function f;

	private boolean postfixVisible;

	public MyPanel3()
		{
		setLayout(null);
		setBackground(Color.lightGray);

		f = FunctionFactory.makeFunction();
		postfixVisible = false;

		infixLabel = new Label(" f(x)=");
		infixLabel.setSize(45, 17);
		infixLabel.setLocation(10, 268);
		infixLabel.setVisible(true);
		infixLabel.setFont(SMALL_FONT);
		infixLabel.setBackground(Color.lightGray);
		add(infixLabel);

		infix = new TextField(f.getInfix());
		infix.setSize(330, 25);
		infix.setLocation(60, 265);
		infix.setVisible(true);
		infix.setBackground(Color.white);
		add(infix);

		postfixLabel = new Label("postfix:");
		postfixLabel.setSize(45, 17);
		postfixLabel.setLocation(10, 303);
		postfixLabel.setVisible(false);
		postfixLabel.setFont(SMALL_FONT);
		postfixLabel.setBackground(Color.lightGray);
		add(postfixLabel);

		postfix = new TextField(f.getPostfix());
		postfix.setSize(260, 25);
		postfix.setLocation(60, 300);
		postfix.setVisible(false);
		postfix.setEditable(false);
		postfix.setBackground(Color.white);
		add(postfix);

		showHide = new Button("Postfix");
		showHide.setSize(60, 30);
		showHide.setLocation(330, 298);
		showHide.setVisible(true);
		showHide.setBackground(Color.white);
		add(showHide);

		graph = new GraphCanvas(f);
		graph.setSize(380, 245);
		graph.setLocation(10, 10);
		graph.setVisible(true);
		graph.setBackground(Color.white);
		add(graph);

		infix.addActionListener(this);
		showHide.addActionListener(this);
		}

	public void actionPerformed(ActionEvent e)
		{
		if (e.getSource() == showHide)
			{
			postfixVisible = !postfixVisible;
			postfix.setVisible(postfixVisible);
			postfixLabel.setVisible(postfixVisible);
			}
		else
			{
			f.setInfix(infix.getText());
			postfix.setText(f.getPostfix());
			graph.repaint();
			}
		}
	}