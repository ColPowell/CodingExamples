import java.awt.*;
import java.awt.event.*;

public class Charstack
{
	private char data[];
	private int top;
	public Charstack()
	{
		data = new char[50];
		top = -1;
	}
	public void push(char ch)
	{
		data[++top] = ch;
	}
	public char pop()
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

	public char peek()
	{
		if(empty())
			return 0;
		return(data[top]);
	}


}