// CH13_Calculaort.java
// 작성자 : 21700760 하주영

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH13_Calculator extends JFrame implements ActionListener
{
	public static final int WIDTH = 600;
	public static final int HEIGHT = 400;
	
	private JTextField inputOutputField;
	private double result = 0.0; // 연산의 결과값 저장
	
	public static void main(String[] args)
	{
		CH13_Calculator cal = new CH13_Calculator();
		cal.setVisible(true);
	}
	
	public CH13_Calculator()
	{
		setTitle("Adding Machine");
		addWindowListener(new WindowDestroyer());
		setSize(WIDTH, HEIGHT);
		Container contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());
		
		JPanel buttonPanel = new JPanel();
		buttonPanel.setBackground(Color.GRAY);
		buttonPanel.setLayout(new FlowLayout());
		
		// 버튼을 추가하는 부분
		// 덧셈버튼
		JButton addButton = new JButton("Add");
		addButton.addActionListener(this);
		buttonPanel.add(addButton);
		// 뺄셈버튼
		JButton subtractButton = new JButton("Subtract");
		subtractButton.addActionListener(this);
		buttonPanel.add(subtractButton);
		// 곱셈버튼
		JButton multiplyButton = new JButton("Multiply");
		multiplyButton.addActionListener(this);
		buttonPanel.add(multiplyButton);
		// 나눗셈버튼
		JButton divideButton = new JButton("Devide");
		divideButton.addActionListener(this);
		buttonPanel.add(divideButton);
		// 리셋버튼
		JButton resetButton = new JButton("Reset");
		resetButton.addActionListener(this);
		buttonPanel.add(resetButton);
		
		contentPane.add(buttonPanel, BorderLayout.SOUTH); // 버튼배치위치 세팅
		
		JPanel textPanel = new JPanel();
		textPanel.setBackground(Color.BLUE);
		textPanel.setLayout(new FlowLayout());
		
		inputOutputField = new JTextField("Numbers go here.", 30);
		inputOutputField.setBackground(Color.WHITE);
		textPanel.add(inputOutputField);
		contentPane.add(textPanel, BorderLayout.CENTER);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		try
		{
			tryingCorrectNumberFormats(e);
		}
		catch(NumberFormatException e2)
		{
			inputOutputField.setText("Error: Reenter Number.");
		}
	}
	
	public void tryingCorrectNumberFormats(ActionEvent e)
	{
		if(e.getActionCommand().equals("Add"))
		{
			result = result+stringToDouble(inputOutputField.getText());
			inputOutputField.setText(Double.toString(result));
		}
		else if(e.getActionCommand().equals("Subtract"))
		{
			result = result-stringToDouble(inputOutputField.getText());
			inputOutputField.setText(Double.toString(result));
		}
		else if(e.getActionCommand().equals("Multiply"))
		{
			result = result*stringToDouble(inputOutputField.getText());
			inputOutputField.setText(Double.toString(result));
		}
		else if(e.getActionCommand().equals("Devide"))
		{
			result = result/stringToDouble(inputOutputField.getText());
			inputOutputField.setText(Double.toString(result));
		}
		else if(e.getActionCommand().equals("Reset"))
		{
			result = 0.0;
			inputOutputField.setText("0.0");
		}
		else
			inputOutputField.setText("Error in cal code");
	}
	
	private static double stringToDouble(String stringObject)
	{
		return Double.parseDouble(stringObject.trim());
	}
	
	public class WindowDestroyer extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
	    {
	         System.exit(0);
	    }
	}
}
