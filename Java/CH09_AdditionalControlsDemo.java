// CH09_AdditionalControlsDemo.java
// 작성자 : 21700760 하주영

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.VBox;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.Spinner;
import javafx.scene.control.SpinnerValueFactory;
import javafx.scene.control.ChoiceBox;
import javafx.collections.FXCollections;
import javafx.scene.control.Label;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class CH09_AdditionalControlsDemo extends Application
{
	public static void main(String[] args)
	{
		launch(args);
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		VBox root = new VBox();
		
		// Select Frist Day - Radio Buttons
		root.getChildren().add(new Label("First Day-Radio Buttons"));
		ToggleGroup toggleCrust = new ToggleGroup();
		RadioButton rbMon1 = new RadioButton("Mon1");
		rbMon1.setToggleGroup(toggleCrust);
		rbMon1.setSelected(true);
		RadioButton rbTue1 = new RadioButton("Tue1");
		rbTue1.setToggleGroup(toggleCrust);
		rbTue1.setSelected(true);
		RadioButton rbWed1 = new RadioButton("Wed1");
		rbWed1.setToggleGroup(toggleCrust);
		rbWed1.setSelected(true);
		RadioButton rbThu1 = new RadioButton("Thu1");
		rbThu1.setToggleGroup(toggleCrust);
		rbThu1.setSelected(true);
		
		root.getChildren().add(rbMon1);
		root.getChildren().add(rbTue1);
		root.getChildren().add(rbWed1);
		root.getChildren().add(rbThu1);
		
		// Select Second Day - CheckBox
		root.getChildren().add(new Label("Select Second Day - CheckBox"));
		CheckBox cbMon2 = new CheckBox("Mon2");
		CheckBox cbTue2 = new CheckBox("Tue2"); 
		CheckBox cbWed2 = new CheckBox("Wed2");
		CheckBox cbThu2 = new CheckBox("Thu2");
		root.getChildren().add(cbMon2);
		root.getChildren().add(cbTue2);
		root.getChildren().add(cbWed2);
		root.getChildren().add(cbThu2);
		
		
		// Select Third Day - Spinner with Integer(1~4)
		root.getChildren().add(new Label("Select Third Day - Spinner with Integer(1~4)")); 
		Spinner<Integer> spinnerQuantity = new Spinner(); 
		final int defaultValue = 1;
		// Value factory.
		SpinnerValueFactory<Integer> quantityFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(1, 4, defaultValue);
		spinnerQuantity.setValueFactory(quantityFactory);
		root.getChildren().add(spinnerQuantity);
		
		// Select Forth Day - ChoiceBox
		root.getChildren().add(new Label("Select Forth Day - ChoiceBox"));
		ChoiceBox<String> cbModes = new ChoiceBox<String>( FXCollections.observableArrayList("Mon4", "Tue4", "Wed4", "Thu4"));
		root.getChildren().add(cbModes);
		
		// Button to display selections
		Button btnSelections = new Button("Get Selections");
		
		// Set the event handler when the button is clicked 
		btnSelections.setOnAction(new EventHandler<ActionEvent>()
		{
			@Override
			public void handle(ActionEvent event)
			{
				System.out.println("First Day-Radio Buttons");
				System.out.println("Mon1: " + rbMon1.isSelected());
				System.out.println("Tue1: " + rbTue1.isSelected());
				System.out.println("Wed1: " + rbWed1.isSelected());
				System.out.println("Thu1: " + rbThu1.isSelected());
				
				System.out.println("\nSecond Day - Checkbox");
				System.out.println("Mon2: " + cbMon2.isSelected());
				System.out.println("Tue2: " + cbTue2.isSelected());
				System.out.println("Wed2: " + cbWed2.isSelected());
				System.out.println("Thu2: " + cbThu2.isSelected());
				
				System.out.println("\nThird Day - Spinner with Integer");
				System.out.println("Third Day: " + spinnerQuantity.getValue());
				
				System.out.println("\nFourth Day - ChoiceBox");
				System.out.println("Fourth Day: " + cbModes.getValue());
			}
		}
		);
		root.getChildren().add(btnSelections);
		
		Scene scene = new Scene(root, 350, 300);
		primaryStage.setTitle("Additional Controls Demo");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}

