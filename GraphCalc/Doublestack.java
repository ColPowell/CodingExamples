import java.awt.*;
import java.awt.event.*;

public class Doublestack
{
	private double data[];
	public int top;
	public Doublestack()
	{
		data = new double[50];
		top = -1;
	}
	public void push(double ch)
	{
		data[++top] = ch;
	}
	public double pop()
	{
		if(empty())
			return 0;
		return data[top--];
	}
	public boolean empty()
	{
		return top < 0;
	}
	public String toString()
	{
		String s = "CharStack: ";
		for(int t = 0; t <= top; t++)
		{
			s+=" "+data[t];
		}
		return s;
	}

	public void clear()
	{
		top = -1;
	}
	public void print()
	{
		for(int i = 0; i <= top; i++)
			System.out.println(i+": "+data[i]);
	}


}