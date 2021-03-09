// CH10_FileOraganizer.java
// 작성자 :  21700760 하주영

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.FlowPane;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import java.io.File;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

public class CH10_FileOrganizer extends Application
{
	private TextField fileNameField; // 결과를 출력할 파일에 대한 TextField
	private TextField degreeField;   // 곱할 값에 대한 TextField
	
	public static void main(String[] args)
	{
		launch(args);
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		final int WIDTH = 400;
		final int HEIGHT = 300;
		final int NUMBER_OF_PIXELS = 300;
		
		FlowPane root = new FlowPane();
		root.setPadding(new Insets(20));
		root.setVgap(10);
		root.setHgap(10);
		
		// Text field를 생성 및 출력
		fileNameField = new TextField("Enter Output file name here");
		fileNameField.setPrefWidth(NUMBER_OF_PIXELS);
		root.getChildren().add(fileNameField);
		
		degreeField = new TextField("Enter Integer Number");
		degreeField.setPrefWidth(NUMBER_OF_PIXELS);
		root.getChildren().add(degreeField);
		
		// Button 생성 및 출력
		Button showButton = new Button("Multiply");
		root.getChildren().add(showButton);
		showButton.setOnAction(new EventHandler<ActionEvent>()
		{
			@Override
			public void handle(ActionEvent event)
			{
				Multiply();
			}
		}
		);
		
		Button resetButton = new Button("Reset");
		root.getChildren().add(resetButton);
		resetButton.setOnAction(new EventHandler<ActionEvent>()
		{
			@Override
			public void handle(ActionEvent event)
			{
				reset();
			}
		}
		);
		
		Scene scene = new Scene(root, WIDTH, HEIGHT);
		primaryStage.setTitle("File Organizer");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	// 곱하는 연산 수행
	private void Multiply()
	{
		Scanner fileInput = null;
		PrintWriter fileOutput = null;
		String fileName = fileNameField.getText(); // 출력파일 이름에 대한 값을 받아옴
		String degree = degreeField.getText();     // 곱할 값을 받아옴
		File fileObject = new File("input.txt");
		
		if(!fileObject.exists())
			fileNameField.setText("No such file");
		else if(!fileObject.canRead())
			fileNameField.setText("That file is not readable.");
		else
		{
			try
			{
				fileInput = new Scanner(fileObject);
				fileOutput = new PrintWriter(fileName);
				
				String operand; // 파일로부터 읽어올 피연산자 내용
				while(fileInput.hasNextLine())
				{
					operand = fileInput.nextLine();
					fileOutput.println(Integer.parseInt(operand)*Integer.parseInt(degree)); // 계산후 파일로 출력
				}
				fileNameField.setText("output file : " + fileName);
				degreeField.setText("completed!");
			}
			catch(IOException e)
			{
				degreeField.setText("Error opening the file " + fileName);
			}
		}
		fileInput.close();
		fileOutput.close();
	}
	
	// 메시지 reset
	private void reset()
	{
		fileNameField.setText("Enter Output file name here");
		degreeField.setText("Enter Integer Number");
	}
}
