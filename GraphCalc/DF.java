public class DF implements Function
{
	private String infix;
	private String postfix;
	private double numbers[];
	private Doublestack memory;
	private Charstack operators;

	public DF()
	{
		infix = "2*x";
		postfix = "#x*";
		numbers = new double[30];
		numbers[0]=2;
		memory = new Doublestack();
	}

	public void setInfix(String in)
	{
		int index = 0;
		operators = new Charstack();
		boolean firstTime = true;
		infix = in + " ";
		postfix = "";
		operators.push(' ');
		for(int n = 0; n<infix.length();n++)
		{

			char ch = infix.charAt(n);
			if(ch == '-'&&firstTime==true)
			{
				ch = '$';
				operators.push(ch);
			}
			if(ch != ' ')
				firstTime = false;
			switch(ch)
			{

				case 'x':
					postfix += 'x';
					break;

				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
					int m = n+1;
					while(IsADigit(infix.charAt(m))) m++;
					numbers[index++] = convert(infix.substring(n,m));
					n = m-1;
					postfix += '#';
					break;

				case '$':
					memory.push(-memory.pop());
					break;
				case 'a': case 'r': case 's': case 'c': case 'e': case 'l':
					operators.push('(');
					operators.push(ch);
					firstTime = true;
					n++;
					break;

				case '+': case'-': case '*': case '/': case '^':
					while(leftFirst(operators.peek(),ch))
					{
						postfix+=operators.pop();
					}
					operators.push(ch);

					break;
				case '(':
					operators.push(ch);
					firstTime = true;
					break;
				case ')':
					while(operators.peek()!='(')
						postfix+=operators.pop();
					operators.pop();
					break;

			}
		}

		System.out.println(operators.peek());
		postfix += operators.pop();
		while(operators.peek()!=' ')
			postfix+=operators.pop();

	}

	private boolean IsADigit(char c)
	{
		if('0' <= c && c <= '9')
			return true;
		if(c == '.')
			return true;
		return false;
	}

	private boolean leftFirst(char left, char right)
	{
		int a = rank(left);
		int b = rank(right);
		if(left =='^' && right == '^')
			return false;
		return a>=b;
	}

	private int rank(char c)
	{
		switch(c)
		{
			case '+': case'-': return 1;
			case '*': case '/': return 2;
			case '$': return 3;
			case '^': return 4;
			default: return 0;
		}
	}

	public double getValue(double x)
	{
		memory.clear();
		int index = 0;
		for(int n = 0; n < postfix.length(); n++)
		{
			switch(postfix.charAt(n))
			{
				case '#': memory.push(numbers[index++]);
					break;
				case 'x': memory.push(x);
					break;
				case '+':
					memory.push((memory.pop()) + (memory.pop()));
					break;
				case '-':
					double tempt1 = memory.pop();
					double temp2 = memory.pop();
					memory.push(temp2 - tempt1);
					break;
				case '*':
					memory.push((memory.pop()) * (memory.pop()));
					break;
				case '/':
					double temp1 = memory.pop();
					double tempt2 = memory.pop();
					memory.push(tempt2 / temp1);
					break;
				case '^':
					double temp12 = memory.pop();
					double tempt12 = memory.pop();
					memory.push(Math.pow(tempt12,temp12));
					break;
				case '$':
					double a = memory.pop();
					memory.push(-a);
					break;
				case 'r':
					memory.push(Math.sqrt(memory.pop()));
					break;
				case 'a':
					memory.push(Math.abs(memory.pop()));
					break;
				case 's':
					memory.push(Math.sin(memory.pop()));
					break;
				case 'c':
					memory.push(Math.cos(memory.pop()));
					break;
				case 'e':
					memory.push(Math.exp(memory.pop()));
					break;
				case 'l':
					memory.push(Math.log(memory.pop()));
					break;
			}
		}
		return memory.pop();
	}

	public String toString()
	{
		return "DF:infix=" + getInfix()+ " postfix=" + getPostfix();
	}

	public String getInfix()
	{
		return infix;
	}
	public String getPostfix()
	{
		String result = "";
		int num=0;
		for (int n=0; n<postfix.length(); n++)
		{
			if (postfix.charAt(n) == '#')
				result += " " + numbers[num++];
			else
				result += " " + postfix.charAt(n);
		}
		if (result.length() > 0)
			result = result.substring(1); // remove blank at beginning
		return result;
	}

	public static double convert(String s)
	{
		try
		{
			return (new Double(s)).doubleValue();
		}
		catch (NumberFormatException nfe)
		{
			return -9876.54;
		}
	}



}