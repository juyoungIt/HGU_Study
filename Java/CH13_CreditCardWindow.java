// CH13_CreditCardWindow.java
// 작성자 : 21700760 하주영

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH13_CreditCardWindow extends JFrame implements ActionListener
{
	// 기본적인 창을 생성
	public static final int WIDTH = 350;  // 생성하는 window의 가로크기
	public static final int HEIGHT = 80; // 생성하는 window의 세로크기
	private JTextField inputField; // textField
	private JLabel status;
	private String cardNum; // 사용자 입력 카드번호
	
	
	// constructor
	public CH13_CreditCardWindow()
	{
		setTitle("Enter a Credit Card number"); // 생성 window 제목설정
		addWindowListener(new WindowDestroyer());
		setSize(WIDTH, HEIGHT); // 생성할 window의 크기설정
		Container contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());
		
		// text panel 생성 및 Label 생성
		JPanel textPanel = new JPanel();
		textPanel.setBackground(Color.LIGHT_GRAY);
		textPanel.setLayout(new FlowLayout());
		inputField = new JTextField(20);
		inputField.setBackground(Color.WHITE);
		textPanel.add(inputField);
		status = new JLabel(""); // 처리결과를 표시하는 label
		textPanel.add(status, BorderLayout.NORTH);
		contentPane.add(textPanel, BorderLayout.CENTER);
		
		// 버튼을 위치시키기 위한 panel 설정
		JPanel buttonPanel = new JPanel();
		buttonPanel.setBackground(Color.LIGHT_GRAY);
		buttonPanel.setLayout(new FlowLayout());
		
		// accept 버튼 추가
		JButton acceptButton = new JButton("Accept");
		acceptButton.addActionListener(this);
		buttonPanel.add(acceptButton);
		contentPane.add(buttonPanel, BorderLayout.EAST); // 버튼배치위치 세팅
	}
	
	public void actionPerformed(ActionEvent e)
	{
		try
		{
			tryingCorrectNumberFormats(e);
		}
		catch(NumberFormatException e2)
		{
			inputField.setText("Error: Reenter Number.");
		}
	}
	
	public void tryingCorrectNumberFormats(ActionEvent e)
	{
		if(e.getActionCommand().equals("Accept"))
		{
			cardNum = inputField.getText().trim(); // 사용자 입력정보를 가져옴(공백은 반영하지 않음)
			// 입력한 카드번호가 16자리 숫자일 경우
			if(cardNum.length() == 16)
			{
				status.setText("Numner accepted " + cardNum);
				inputField.setText(""); // 입력된 문자 삭제
			}
			else // 입력한 카드번호가 16자리 숫자가 아닐경우
			{
				status.setText("Number rejected " + cardNum);
			}
		}
		else
			inputField.setText("Error in cal code");
	}
	
	
	public class WindowDestroyer extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
	    {
	         System.exit(0);
	    }
	}
}
