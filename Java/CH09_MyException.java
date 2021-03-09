// CH09_MyException.java
// 작성자 : 21700760 하주영

public class CH09_MyException extends Exception
{
	// default constructor
	public CH09_MyException()
	{
		super("String should not include\nspecial character $.");
	}
	
	// constructor
	public CH09_MyException(String message)
	{
		super(message);
	}
	
	// override toString method
	public String toString()
	{
		return super.getMessage();
	}
}
