// CH12_Stack
// 작성자 : 21700760 하주영

public class CH12_Stack
{
	private ListNode top; // stack의 top 
	
	private class ListNode
	{
		private String data;   // 데이터를 저장하는 부분
		private ListNode link; // link 값을 저장하는 부분 
		
		// default constructor
		public ListNode()
		{
			link = null;
			data = null;
		}
		
		// constructor
		public ListNode(String newData, ListNode linkValue)
		{
			data = newData;
			link =linkValue;
		}
	}
	
	public void Push(String str)
	{
		top = new ListNode(str, top);
	}
	
	public void Pop()
	{
		if(top != null)
			top = top.link;
		else
		{
			System.out.println("Deletingo from an empty stack");
			System.exit(0);
		}
	}
	
	public void showData()
	{
		System.out.println("============\n" + "Stack Status\n" + "============"); // header 부분출력
		ListNode position = top;
		while(position != null)
		{
			System.out.println(position.data + "\n------------"); // 저장된 내용출력
			position = position.link; // 다음위치로 이동
		}
	}
}
