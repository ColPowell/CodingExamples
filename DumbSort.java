import java.awt.*;
import java.awt.event.*;

public class DumbSort implements ASort
{
	private int howMany;
	private int data[], temp[];

	public void sort(AList l)
	{
		howMany = l.getHowMany();
		data = l.getData();
		temp = null;
		temp = new int[howMany];
		sortIt();
	}

	private void sortIt()
	{
		while(true)
		{
			for(int x = 0; x < howMany; x++)
			{
				int firstRandom = (int)(Math.random()*howMany);
				int secondRandom = (int)(Math.random()*howMany);
				while(true)
				{
					if(firstRandom != secondRandom) break;
					secondRandom = (int)(Math.random()*howMany);
				}
				if(secondRandom < firstRandom)
				{
					if(data[secondRandom] > data[firstRandom])
					{
						int temp = data[firstRandom];
						data[firstRandom] = data[secondRandom];
						data[secondRandom] = temp;
					}
				}
				else
				{
					if(data[secondRandom] < data[firstRandom])
					{
						int temp = data[firstRandom];
						data[firstRandom] = data[secondRandom];
						data[secondRandom] = temp;
					}
				}
			}
			if(isSorted()) break;
		}
	}

	public boolean isSorted()
	{
		//System.out.println("Status of list: ");
		for(int x = 1; x < howMany; x++)
		{
			//System.out.println(x);
			if(data[x-1] > data[x]) return false;
		}
		//System.out.println("\n");
		return true;
	}

	public String getName()
	{
		return "Dumb Sort";
	}


}
