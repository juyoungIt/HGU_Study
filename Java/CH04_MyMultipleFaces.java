// CH04_MyMultitpleFaces.java
// 작성자 : 21700760 하주영

import javafx.application.Application;
import javafx.scene.canvas.Canvas;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.stage.Stage;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.shape.ArcType;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;

public class CH04_MyMultipleFaces extends Application 
{
// 본 프로그램에 필요한 각종 상수값들의 정의
	public static final int WINDOW_WIDTH = 650;
	public static final int WINDOW_HEIGHT = 400;
	
	public static final int FACE_DIAMETER = 50;
	public static final int X_FACE0 = 10;
	public static final int Y_FACE0 = 5;
	
	public static final int EYE_WIDTH = 5;
	public static final int EYE_HEIGHT = 10;
	public static final int X_RIGHT_EYE0 = 20;
	public static final int Y_RIGHT_EYE0 = 15;
	public static final int X_LEFT_EYE0 = 45;
	public static final int Y_LEFT_EYE0 = Y_RIGHT_EYE0;
	
	public static final int NOSE_DIAMETER = 5;
	public static final int X_NOSE0 = 32;
	public static final int Y_NOSE0 = 25;
	
	public static final int MOUTH_WIDTH = 30;
	public static final int MOUTH_HEIGHT0 = 0;
	public static final int X_MOUTH0 = 20;
	public static final int Y_MOUTH0 = 35;
	public static final int MOUTH_START_ANGLE = 180;
	public static final int MOUTH_EXTENT_ANGLE = 180;
	
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
		
		int i,j; // 반복문 변수 
		int xOffset, yOffset; // 원들의 좌표를 효율적으로 이동시키기 위한 변수
		int x = 0; // 얼굴의 좌표를 변환하는 데 사용하기 위한 변수선언
		
		// 얼굴의 묶을 반복적으로 그리는 부분(3묶음 짜리)
		for (i=0; i<3; i++)
		{
			// 반복되는 형태의 3개의 얼굴을 그리는 부분(노란얼굴, 초록얼굴, 회색얼굴)
			for(j=0 ; j<3 ; j++)
			{
				xOffset = 50 * x; // 얼굴의 x좌표 이동에 관련있는 부분
				yOffset = 30 * x; // 얼굴의 y좌표 이동에 관련있는 부분
				// 얼굴의 묶음 중 첫번째 얼굴이라면
				if((j+1)%3 == 1)
				{
					gc.setFill(Color.YELLOW); // 노란얼굴을 그림
					gc.fillOval(X_FACE0 + xOffset, Y_FACE0 + yOffset, FACE_DIAMETER, FACE_DIAMETER);
				}
				else if((j+1)%3 == 2) // 얼굴의 묶음 중 두번째 얼굴이라면
				{
					gc.setFill(Color.GREEN); // 초록얼굴을 그림
					gc.fillOval(X_FACE0 + xOffset, Y_FACE0 + yOffset, FACE_DIAMETER, FACE_DIAMETER);
				}
				else // (j+1%3 == 0) 인 경우, 얼굴의 묶음 중 세번째 얼굴이라면
				{
					gc.setFill(Color.GRAY); // 회색얼굴을 그림
					gc.fillOval(X_FACE0 + xOffset, Y_FACE0 + yOffset, FACE_DIAMETER, FACE_DIAMETER);
				}
				// 얼굴 태두리를 그리는 부분
				gc.setStroke(Color.BLACK); // 테두리를 칠하기 위해 method setStroke 사용
				gc.strokeOval(X_FACE0 + xOffset, Y_FACE0 + yOffset,FACE_DIAMETER, FACE_DIAMETER);
				// 눈을 그리는 부분
				gc.setFill(Color.BLUE);
				gc.fillOval(X_RIGHT_EYE0 + xOffset, Y_RIGHT_EYE0 + yOffset, EYE_WIDTH, EYE_HEIGHT); 
				gc.fillOval(X_LEFT_EYE0 + xOffset, Y_LEFT_EYE0 + yOffset, EYE_WIDTH, EYE_HEIGHT);
				// 코를 그리는 부분
				gc.setFill(Color.BLACK);
				gc.fillOval(X_NOSE0 + xOffset, Y_NOSE0 + yOffset, NOSE_DIAMETER, NOSE_DIAMETER);
				// 입을 그리는 부분
				gc.setStroke(Color.RED); // 테두리를 칠하기 위해 method setStroke 사용
				gc.strokeArc(X_MOUTH0 + xOffset, Y_MOUTH0 + yOffset, MOUTH_WIDTH, MOUTH_HEIGHT0 + 3 * i + 1, MOUTH_START_ANGLE, MOUTH_EXTENT_ANGLE, ArcType.OPEN);
				// 문자를 붙이는 부분
				gc.setFont(Font.font("Times New Roman", 12));
				gc.fillText("Kiss!!.", X_FACE0 + xOffset + FACE_DIAMETER, Y_FACE0 + yOffset + 5);
				x++; // 얼굴의 좌표를 이동하기 위한, offset의 값을 변경하기 위해 변수x의 값 1증가
			}
		}
		
		// 반복문 종료 후 나머지 2개의 얼굴을 그리는 부분
		xOffset = 50 * x; // 새로운 얼굴을 그리기 위해 50 * x만큼 x좌표 방향으로 이동
		yOffset = 30 * x; // 새로운 얼굴을 그리기 위해 30 * y만큼 y좌표 방향으로 이동
		
		// Kiss, Kiss. 문자를 가진 얼굴을 그리는 부분
		// 얼굴을 그리는 부분
		gc.setStroke(Color.BLACK); // 테두리를 칠하기 위해 method setStroke 사용
		gc.strokeOval(X_FACE0 + xOffset, Y_FACE0 + yOffset, FACE_DIAMETER, FACE_DIAMETER);
		// 눈을 그리는 부분
		gc.setFill(Color.BLUE);
		gc.fillOval(X_RIGHT_EYE0 + xOffset, Y_RIGHT_EYE0 + yOffset, EYE_WIDTH, EYE_HEIGHT); 
		gc.fillOval(X_LEFT_EYE0 + xOffset, Y_LEFT_EYE0 + yOffset, EYE_WIDTH, EYE_HEIGHT);
		// 코를 그리는 부분
		gc.setFill(Color.BLACK);
		gc.fillOval(X_NOSE0 + xOffset, Y_NOSE0 + yOffset, NOSE_DIAMETER, NOSE_DIAMETER);
		// 입을 그리는 부분
		gc.setFill(Color.RED);
		gc.fillOval(X_MOUTH0 + xOffset + 10, Y_MOUTH0 + yOffset, MOUTH_WIDTH - 20, MOUTH_WIDTH - 20);
		// Kiss, Kiss. 문자를 추가하는 부분
		gc.setFont(Font.font("Times New Roman", 12));
		gc.setFill(Color.BLACK); // 출력하는 글자의 색을 검은색으로 바꾸기 위한 부분
		gc.fillText("Kiss, Kiss.", X_FACE0 + xOffset + FACE_DIAMETER, Y_FACE0 + yOffset + 5);
		x++; // 다음좌표로 이동해서 얼굴을 그리기 위한 offset의 값의 변화에 영향을 미치는 x값 1증가
		
		// Tee Hee 문자를 가지는 얼굴을 출력하는 부분
		xOffset = 50 * x; // 새로운 얼굴을 그리기 위해 50 * x만큼 x좌표 방향으로 이동
		yOffset = 30 * x; // 새로운 얼굴을 그리기 위해 30 * y만큼 y좌표 방향으로 이동
		// 얼굴을 그리는 부분
		gc.setFill(Color.GRAY);
		gc.fillOval(X_FACE0 + xOffset, Y_FACE0 + yOffset, FACE_DIAMETER, FACE_DIAMETER); 
		gc.strokeOval(X_FACE0 + xOffset, Y_FACE0 + yOffset, FACE_DIAMETER, FACE_DIAMETER);
		// 눈을 그리는 부분
		gc.setFill(Color.BLUE);
		gc.fillOval(X_RIGHT_EYE0 + xOffset, Y_RIGHT_EYE0 + yOffset,EYE_WIDTH, EYE_HEIGHT); 
		gc.fillOval(X_LEFT_EYE0 + xOffset, Y_LEFT_EYE0 + yOffset, EYE_WIDTH, EYE_HEIGHT);
		// 코를 그리는 부분
		gc.setFill(Color.BLACK); 
		gc.fillOval(X_NOSE0 + xOffset, Y_NOSE0 + yOffset, NOSE_DIAMETER, NOSE_DIAMETER);
		// 입을 그리는 부분
		gc.setStroke(Color.RED);
		gc.strokeArc(X_MOUTH0 + xOffset, Y_MOUTH0 + yOffset, MOUTH_WIDTH, MOUTH_HEIGHT0 + 3 * i + 1, MOUTH_START_ANGLE, MOUTH_EXTENT_ANGLE, ArcType.OPEN);
		// Tee Hee 문자를 출력하는 부분
		gc.setFont(Font.font("Courier New ", 16));
		gc.setFill(Color.BLACK); // 출력하는 글자의 색을 검은색으로 바꾸기 위한 부분
		gc.fillText("Tee Hee.", X_FACE0 + xOffset + FACE_DIAMETER, Y_FACE0 + yOffset + 5);
		
		root.getChildren().add(canvas);
		primaryStage.setTitle("MultipleFaces in JavaFX");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
