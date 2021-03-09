// #4. CH05_MyJavaFX.java
// 작성자 : 21700760 하주영

import javafx.application.Application;
import javafx.scene.canvas.Canvas;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.stage.Stage;
import javafx.scene.canvas.GraphicsContext;
//import javafx.scene.shape.ArcType;
//import javafx.scene.paint.Color;
import javafx.scene.image.Image;
import javafx.scene.effect.Reflection;
import javafx.scene.effect.Glow;
import javafx.scene.effect.BoxBlur;
import javafx.scene.effect.GaussianBlur;

public class CH05_MyJavaFX extends Application
{
	public static void main(String[] args)
	{
		launch(args);
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		// 이미지를 그리는 공간을 만들기 위한 기본적 세팅
		Group root = new Group();
		Scene scene = new Scene(root);
		Image img = new Image("hgulogo.png");
		Canvas canvas = new Canvas(500, 700);
		GraphicsContext gc = canvas.getGraphicsContext2D();
		
		// 이미지를 그리는 부분
		gc.drawImage(img, 1, 1); // 원래 이미지를 그대로 그리기
		
		gc.setEffect(new Reflection()); // Reflection 효과적용
		gc.drawImage(img, 1, img.getHeight()*2); // 효과적용 후 그리기
		
		gc.setEffect(new Glow()); // Glow 효과적용
		gc.drawImage(img, 1, img.getHeight()*4); // 효과적용 후 그리기
		
		gc.setEffect(new BoxBlur()); // BoxBlur 효과적용
		gc.drawImage(img, 1, img.getHeight()*6); // 효과적용 후 그리기
		
		gc.setEffect(new GaussianBlur()); // GaussianBlur 효과적용
		gc.drawImage(img, 1, img.getHeight()*8); // 효과적용 후 그리기
		
		root.getChildren().add(canvas);
		primaryStage.setTitle("Drawing Images in JavaFX");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
