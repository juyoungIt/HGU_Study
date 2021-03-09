// CH15_SundaeCreator.java
// 작성자 : 21700760 하주영

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH15_SundaeCreator extends JFrame implements ActionListener
{
	public static final int WIDTH = 350;
	public static final int HEIGHT = 250;
	
	private JLabel title;
	private JLabel flavor;
	private JLabel topping;
	private JLabel syrup;
	
	// constructor
	public CH15_SundaeCreator()
	{
		setSize(WIDTH, HEIGHT);
		//addWindowListener(new WindowDestroyer());
		
		setTitle("Create a sundae"); // window 제목
		Container contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());
		// 메뉴생성
		JMenu menu1 = new JMenu("Choices"); // choice menu
		JMenu menu2 = new JMenu("Actions"); // action menu
		JMenuItem m;
		
		JMenu flavorMenu = new JMenu("Flavor");
		m = new JMenuItem("Chocolate");
		m.addActionListener(this);
		flavorMenu.add(m);
		m = new JMenuItem("Strawberry");
		m.addActionListener(this);
		flavorMenu.add(m);
		m = new JMenuItem("Vanilla");
		m.addActionListener(this);
		flavorMenu.add(m);
		menu1.add(flavorMenu);
		
		JMenu toppingMenu = new JMenu("Toppings");
		m = new JMenuItem("Chocolate chips");
		m.addActionListener(this);
		toppingMenu.add(m);
		m = new JMenuItem("Sprinkles");
		m.addActionListener(this);
		toppingMenu.add(m);
		m = new JMenuItem("Nuts");
		m.addActionListener(this);
		toppingMenu.add(m);
		m = new JMenuItem("Peppermint");
		m.addActionListener(this);
		toppingMenu.add(m);
		menu1.add(toppingMenu);
		
		JMenu syrupMenu = new JMenu("Syrup");
		m = new JMenuItem("Chocolate Syrup");
		m.addActionListener(this);
		syrupMenu.add(m);
		m = new JMenuItem("Butterscotch");
		m.addActionListener(this);
		syrupMenu.add(m);
		m = new JMenuItem("Berry");
		m.addActionListener(this);
		syrupMenu.add(m);
		menu1.add(syrupMenu);

		m = new JMenuItem("Clear");
		m.addActionListener(this);
		menu2.add(m);
		m = new JMenuItem("Exit");
		m.addActionListener(this);
		menu2.add(m);
		
		// 생성한 메뉴들을 메뉴바에 추가
		JMenuBar mBar = new JMenuBar();
		mBar.add(menu1);
		mBar.add(menu2);
		setJMenuBar(mBar);
		
		// 레이블 추가
		JPanel textPanel = new JPanel();
		textPanel.setBackground(Color.LIGHT_GRAY);
		textPanel.setLayout(new GridLayout(4,1));
		
		Font font1 = new Font("Times", Font.ITALIC, 50);
		title = new JLabel("Your Sundae"); // 제목을 표시하는 레이블
		title.setFont(font1);
		textPanel.add(title, BorderLayout.CENTER);
		
		Font font2 = new Font("Times", Font.ITALIC, 20);
		flavor = new JLabel("Flavor: none"); 
		flavor.setFont(font2);
		textPanel.add(flavor, BorderLayout.CENTER);
		
		Font font3 = new Font("Times", Font.ITALIC, 20);
		topping = new JLabel("Topping: none");
		topping.setFont(font3);
		textPanel.add(topping, BorderLayout.CENTER);
		
		Font font4 = new Font("Times", Font.ITALIC, 20);
		syrup = new JLabel("Syrup: none");
		syrup.setFont(font4);
		textPanel.add(syrup, BorderLayout.CENTER);
		contentPane.add(textPanel, BorderLayout.CENTER);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		String actionCommand = e.getActionCommand();
		if(actionCommand.equals("Chocolate"))
			flavor.setText("Flavor: Chocolate");
		else if(actionCommand.equals("Strawberry"))
			flavor.setText("Flavor: Strawberry");
		else if(actionCommand.equals("Vanilla"))
			flavor.setText("Flavor: Vanilla");
		else if(actionCommand.equals("Chocolate chips"))
			topping.setText("Topping: Chocolate chips");
		else if(actionCommand.equals("Sprinkles"))
			topping.setText("Topping: Sprinkles");
		else if(actionCommand.equals("Nuts"))
			topping.setText("Topping: Nuts");
		else if(actionCommand.equals("Peppermint"))
			topping.setText("Topping: Peppermint");
		else if(actionCommand.equals("Chocolate Syrup"))
			syrup.setText("Syrup: Chocolate Syrup");
		else if(actionCommand.equals("Butterscotch"))
			syrup.setText("Syrup: Butterscotch");
		else if(actionCommand.equals("Berry"))
			syrup.setText("Syrup: Berry");
		else if(actionCommand.equals("Clear"))
		{
			flavor.setText("Flavor: none");
			topping.setText("Topping: none");
			syrup.setText("Syrup: none");
		}
		else if(actionCommand.equals("Exit"))
			System.exit(0); // 프로세스 종료
		else
			syrup.setText("Syrup: none");
	}
}
