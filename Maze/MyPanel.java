import java.awt.*;
import java.awt.event.*;

public class MyPanel extends Panel implements ActionListener
{
	private Maze maze;
	private Button createMaze, findAnswer, drawMaze, drawAnswer;
	private TextField size;

	public MyPanel()
	{
		setLayout(null);
		setBackground(new Color(200,225,255));
		maze = new Maze();

		createMaze = new Button("Draw Maze(quick)");
		createMaze.setLocation(290,50);
		createMaze.setSize(150,20);
		add(createMaze);
		createMaze.addActionListener(this);

		drawMaze = new Button("Draw Maze(slow)");
		drawMaze.setLocation(290,80);
		drawMaze.setSize(150,20);
		add(drawMaze);
		drawMaze.addActionListener(this);

		findAnswer = new Button("Draw Answer(quick)");
		findAnswer.setLocation(290,110);
		findAnswer.setSize(150,20);
		add(findAnswer);
		findAnswer.addActionListener(this);

		drawAnswer = new Button("Draw Answer(slow)");
		drawAnswer.setLocation(290,140);
		drawAnswer.setSize(150,20);
		add(drawAnswer);
		drawAnswer.addActionListener(this);

		size = new TextField("");
		size.setLocation(290,10);
		size.setSize(150,20);
		size.setBackground(Color.white);
		add(size);
		size.addActionListener(this);

	}

	public void paint(Graphics g)
	{
		maze.paint(g);
	}

	public void actionPerformed(ActionEvent e)
	{
		System.out.println(e);


		if(e.getSource() == createMaze) //creates the maze quick
		{
			String temp = size.getText();
			int a = Integer.parseInt(temp);
			maze.SIZE = a;
			maze.fillMaze();
			maze.fastMaze = true;
		}
		if(e.getSource() == drawMaze)//creates maze slow
		{
			String temp = size.getText();
			int a = Integer.parseInt(temp);
			maze.SIZE = a;
			maze.fillMaze();
			maze.fastMaze = false;
		}
		if(e.getSource() == findAnswer)//draws answer quick
		{
			maze.findSolution();
			maze.fastSolution = true;
		}
		if(e.getSource() == drawAnswer)//draws answer slow
		{
			maze.findSolution();
			maze.fastSolution = false;
		}
		repaint();

	}
}