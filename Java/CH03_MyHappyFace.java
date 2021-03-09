// 작성자 : 21700760 하주영 

import javafx.application.Application; 
import javafx.scene.canvas.Canvas;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.stage.Stage;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.shape.ArcType;
import javafx.scene.paint.Color;

public class CH03_MyHappyFace extends Application
{ 
	public static final int WINDOW_WIDTH = 400; 
	public static final int WINDOW_HEIGHT = 300;
	public static final int FACE_DIAMETER = 200;
	public static final int X_FACE = 100;
	public static final int Y_FACE = 50;
	
	public static final int EYE_WIDTH = 10;
	public static final int EYE_HEIGHT = 20;
	public static final int X_RIGHT_EYE = 155;
	public static final int Y_RIGHT_EYE = 100;
	public static final int X_LEFT_EYE = 230;
	public static final int Y_LEFT_EYE = Y_RIGHT_EYE;
	public static final int NOSE_DIAMETER = 10;
	public static final int X_NOSE = 195; // Center of nose at 200 
	public static final int Y_NOSE = 135;
	public static final int MOUTH_WIDTH = 100;
	public static final int MOUTH_HEIGHT = 50;
	public static final int X_MOUTH = 150;
	public static final int Y_MOUTH = 160;
	public static final int MOUTH_START_ANGLE = 180;
	public static final int MOUTH_DEGREES_SHOWN = 180;
	
	public static void main(String[] args)
	{ 
		launch(args); 
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception
	{
	Group root = new Group();
	Scene scene = new Scene(root);
	Canvas canvas = new Canvas(WINDOW_WIDTH, WINDOW_HEIGHT);
	GraphicsContext gc = canvas.getGraphicsContext2D();
	// 얼굴그리기
	gc.setFill(Color.YELLOW);
	gc.fillOval(X_FACE, Y_FACE, FACE_DIAMETER, FACE_DIAMETER);
	gc.setFill(Color.BLACK);
	gc.strokeOval(X_FACE, Y_FACE, FACE_DIAMETER, FACE_DIAMETER);
	// 눈그리기
	gc.setFill(Color.BLUE);
	gc.fillOval(X_RIGHT_EYE, Y_RIGHT_EYE, EYE_WIDTH, EYE_HEIGHT);
	gc.fillOval(X_LEFT_EYE, Y_LEFT_EYE, EYE_WIDTH, EYE_HEIGHT);
	// 코그리
	gc.setFill(Color.BLACK);
	gc.fillOval(X_NOSE, Y_NOSE, NOSE_DIAMETER, NOSE_DIAMETER);
	// 입그리기
	gc.setFill(Color.RED);
	gc.fillArc(X_MOUTH, Y_MOUTH, MOUTH_WIDTH, MOUTH_HEIGHT,
	MOUTH_START_ANGLE, MOUTH_DEGREES_SHOWN, ArcType.CHORD);
	root.getChildren().add(canvas);
	primaryStage.setTitle("HappyFace in JavaFX");
	primaryStage.setScene(scene); primaryStage.show();
	}
	
}