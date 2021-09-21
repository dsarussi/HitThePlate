#include <math.h>
#include <stdio.h>
#include "glut.h"
#include "CGameHandler.h"
#include "CModel.h"
#include "CCube.h"
#include "CPolygon.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CCylinder.h"
#include "Common.h"
#include "CBall.h"
#include "CBg.h"

CCube cube;
CBall ball;
CBg polygon_in_Bg;

bool show;
double rotate_speed;
bool stop;
double move;
bool stopmove;
double dor;
int frame_number;
CCircle aim , opening;
CCylinder canon;
int point_index;
int bullets_number;
const int num_of_bullets = 50;
CCylinder bullets[num_of_bullets];
CPoint bullet_direction[num_of_bullets];
const int num_of_plates = 20;
CCylinder plates[num_of_plates];
double center_x;
int score;
bool play;
bool instruct;

extern void renderBitmapString(float x, float y, void *font, char *string);
extern void renderVerticalBitmapString(float x, float y, int bitmapHeight, void *font, char *string);

void CGameHandler::StartOfGame()
{
	polygon_in_Bg.ScaleSelfPolygon(2.7,2.7,-1);
	ball.ScaleSelfModel(0.2,0.2,0.2);
	opening.ScalePolygon(50,50,50);
	aim.ScalePolygon(0.5,0.5,0);
	for (int plate_index = 0; plate_index<num_of_plates; plate_index++)
	{
		plates[plate_index].RotateSelfModel(X_AXIS, 90);
		plates[plate_index].ScaleSelfModel(1.25, 0.2, 1.25);
	}
	for (int bullet_index = 0; bullet_index < num_of_bullets; bullet_index++)
		bullets[bullet_index].ScaleSelfModel(0.3,0.3,0.95);

	SetStartPositions();
}

void CGameHandler::SetStartPositions()
{
	instruct=false;
	play=false;
	score=0;
	show=false;
	frame_number=0;
	dor=0;
	stopmove = true;
	rotate_speed = 0.5;
	stop = true;
	move=0;
	bullets_number = 0;



	//variables for game handling
	font = def_font = (int)GLUT_BITMAP_HELVETICA_18;
	ChangeBackgroundColors(2.0/80,90.0/80,155.0/80);


	ball.SetBallColors(1,0.7,0.5,0.3,0.2,0);
	ball.MoveModelCenter(1.4,1,-3);
	opening.MovePolygonCenter(0,0,-20);
	opening.SetPolygonColor(10,30,0);

	aim.MovePolygonCenter(0,0,-19.5);
	aim.SetPolygonColor(0,0,0);
	for (int plate_index = 0; plate_index<num_of_plates; plate_index++)
	{
		plates[plate_index].MoveModelCenter(-10,3,-20);

		int rand_result = random(31); // int between 0 to 30
		plates[plate_index].MoveModelCenter(X_AXIS, -10-rand_result);

		int rand_y = random(5); // int between 0 to 4
		plates[plate_index].MoveModelCenter(Y_AXIS, rand_y);
	}

	CCylinder new_canon;
	new_canon.ScaleSelfModel(1, 1, 2);
	new_canon.MoveModelCenter(0, -3, -9.5);
	
	canon.SetNumberOfPolygons(new_canon.GetNumberOfPolygons());
	for (int i=0; i<canon.GetNumberOfPolygons(); i++)
		canon.SetOnePolygon(i, new_canon.GetPolygon(i));


	point_index = 8;
}

//on each frame:
void CGameHandler::DrawScene()
{
	polygon_in_Bg.DrawPolygon();
	if(play==false)
	{
			polygon_in_Bg.DrawPolygon();
		//opening.DrawPolygon();
	}
	if(show==true)
	{
		for (int plate_index = 0; plate_index<num_of_plates; plate_index++)
		{
			plates[plate_index].DrawModel();
		}
	}



	if(play==true)
	{
		polygon_in_Bg.DrawPolygon();
		canon.DrawModel();\
			aim.DrawPolygon();
		double aim_z = aim.GetPolygonCenter().GetCoordinate(Z_AXIS);
		for (int bullet_index = 0; bullet_index<bullets_number; bullet_index++)
		{
			if (bullets[bullet_index].GetModelCenter().GetCoordinate(Z_AXIS) - aim_z > -0.01) 
				bullets[bullet_index].DrawModel();
		}
	}
}

void CGameHandler::LogicPart()
{
	double plate_width = 1;
	double plate_height = 0.2;
	double plate_depth = 1;

	double bullet_width = 0.1;
	double bullet_height = 0.1;
	double bullet_depth = 0.8;

	CPoint plate_centers[num_of_plates];
	for (int plate_index = 0; plate_index<num_of_plates; plate_index++)
		plate_centers[plate_index] = plates[plate_index].GetModelCenter();

	for (int bullet_index = 0; bullet_index<bullets_number; bullet_index++)
	{
		CPoint bullet_center = bullets[bullet_index].GetModelCenter();
		if (bullet_center.GetCoordinate(Z_AXIS) > -100)
		{
			bullets[bullet_index].MoveModel(bullet_direction[bullet_index]);
			bullet_center.MovePoint(bullet_direction[bullet_index]);

			for (int plate_index = 0; plate_index<num_of_plates; plate_index++)
			{
				CPoint plate_center = plate_centers[plate_index];

				double z_diff = abs(bullet_center.GetCoordinate(Z_AXIS) - plate_center.GetCoordinate(Z_AXIS));
				bool hit_z = z_diff < (plate_depth+bullet_depth)/2;

				double x_diff = abs(bullet_center.GetCoordinate(X_AXIS) - plate_center.GetCoordinate(X_AXIS));
				bool hit_x = x_diff < (plate_width+bullet_width)/2;

				double y_diff = abs(bullet_center.GetCoordinate(Y_AXIS) - plate_center.GetCoordinate(Y_AXIS));
				bool hit_y = y_diff < (plate_height+bullet_height)/2;

				if (hit_x && hit_y && hit_z)
				{
					plates[plate_index].MoveModelCenter(-10,1,-20);
					score++;
				}
			}
		}
	}

	for (int plate_index = 0; plate_index<num_of_plates; plate_index++)
	{
		plates[plate_index].MoveModel(X_AXIS ,move);
		plates[plate_index].RotateSelfModel(Z_AXIS ,5);

		if (plates[plate_index].GetModelCenter().GetCoordinate(X_AXIS) > 10)
		{
			plates[plate_index].MoveModelCenter(X_AXIS, -20);
		}
	}
}


void CGameHandler::WriteText()
{
	if(play==false)
	{
		if(instruct==false)
		{
			font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
			glColor3f(0,0,80);
			renderBitmapString(400, 350, (void *)font, "Press 1 to Start Play");

			font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
			glColor3f(0,0,80);
			renderBitmapString(400, 400, (void *)font, "Press 2 to Instructions");

			font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
			glColor3f(0,0,80);
			renderBitmapString(400, 450, (void *)font, "Press 3 to Exit");
		}
	}
	if(instruct==true)
	{
		if(play==false)
		{
		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 180, (void *)font, "All you need to do is basicly Hit the plate.");
		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 210, (void *)font, "After pressing the 'S' key the plates will come");
		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 240, (void *)font, "From the left side of the screen and moving to the right side.");
				font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 270, (void *)font, "By pressing the space key, the canon will shot bullets.");
				font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 300, (void *)font, "your target is to hit the plate with them.");
				font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 330, (void *)font, "The game will be easier with the aim, a black spot on the screen that");
				font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 360, (void *)font, "help you to know screen that help you to know where you shot to.");
						font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 390, (void *)font, "the canon and the aim will move by pressing the left,right,up and down keys.");
						font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(0,0,80);
		renderBitmapString(200, 420, (void *)font, "After the game will over you can restart him by pressing the 'R' key.");
								font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(100,0,0);
		renderBitmapString(400, 460, (void *)font, "Good luck ! Press 1 to start");
		}
	}
	if(play==true)
	{	
			if(num_of_bullets-bullets_number>0)
			{


		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(100,0,0);
		int x_pos = 10;
		int y_pos = 30;
		renderBitmapString(x_pos, y_pos, (void *)font, "Hit The Plate");

		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(100,0,0);
		int x_pos2 = 10;
		int y_pos2 = 60;
		char bullets_string[20];
		if(bullets_number<num_of_bullets)
		{
			sprintf_s(bullets_string, "Bullets : %d", num_of_bullets-bullets_number);
			renderBitmapString(x_pos2,y_pos2, (void *)font, bullets_string);
		}
		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(100,0,0);
		char plates_string[30];
		{
			sprintf_s(bullets_string, "Score : %d", score );
			renderBitmapString(30,90, (void *)font, plates_string);
		}
			}
			double aim_z = aim.GetPolygonCenter().GetCoordinate(Z_AXIS);
		if((num_of_bullets-bullets_number==0) && (bullets[bullets_number-1].GetModelCenter().GetCoordinate(Z_AXIS) - aim_z <= -0.01) )
		{
			font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
			glColor3f(100,0,0);
			renderBitmapString(400, 340, (void *)font, "Game Over");

		font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
		glColor3f(100,0,0);
		char plates_string[30];
		sprintf_s(plates_string, "Your Final Score : %d", score );
		renderBitmapString(400,370, (void *)font, plates_string);

			font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
			glColor3f(100,0,0);
			renderBitmapString(420, 410, (void *)font, "Press R to restart the game");
		}


		if(move==0)
		{
			font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
			glColor3f(100,0,0);
			int x_pos = 400;
			int y_pos = 300;
			renderBitmapString(x_pos, y_pos, (void *)font, "Press 'S' To Start");	
		}
	}

}

//keys:
void CGameHandler::KeyPressed(char key)
{
	switch (key)
	{
	case ' '://spacebar
		if (bullets_number < num_of_bullets)
		{
			CPoint aim_center = aim.GetPolygonCenter();
			CPoint canon_end = canon.GetPolygon(canon.GetNumberOfPolygons()-1).GetPolygonCenter();
			canon_end.ScalePoint(-1,-1,-1);

			bullet_direction[bullets_number] = aim_center;
			bullet_direction[bullets_number].MovePoint(canon_end);
			bullet_direction[bullets_number].ScalePoint(0.05,0.05,0.05);
			canon_end.ScalePoint(-1,-1,-1);

			bullets[bullets_number].SetModelColor(10,0,5);
			bullets[bullets_number].MoveModelCenter(canon_end);
			bullets_number++;
		}


		break;
	case 13: //Enter
		break;
	case 27://Esc
		break;
	case '1':
		play=true;
		break;
	case '2':
		instruct=true;
		break;
	case '3':
		exit(1);
		break;
	case '4':
		break;
	case '5':
		break;
	case 's':
		if(play==true)
		{
			move=0.05;
			show=true;
		}
		break;
		case 'r':
		SetStartPositions();
		break;
	default:
		break;
	}
}

void CGameHandler::SpecialKeyPressed(char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		move-=0.001;
		canon.RotateSelfModel(Y_AXIS, 1);
		aim.MovePolygon(X_AXIS , -1);
		break;
	case GLUT_KEY_RIGHT:
		aim.MovePolygon(X_AXIS , 1);
		canon.RotateSelfModel(Y_AXIS, -1);
		break;
	case GLUT_KEY_UP:
		aim.MovePolygon(Y_AXIS, 0.5);
		canon.RotateSelfModel(X_AXIS, 0.5);
		break;
	case GLUT_KEY_DOWN:
		aim.MovePolygon(Y_AXIS,-0.5);
		canon.RotateSelfModel(X_AXIS, -0.5);

		break;
	default:
		break;
	}
}

//getting backgroundColor
float CGameHandler::GetBeckgroundColorR()
{
	return BGColor_R;
}

float CGameHandler::GetBeckgroundColorG()
{
	return BGColor_G;
}

float CGameHandler::GetBeckgroundColorB()
{
	return BGColor_B;
}

//internal procedures:
void CGameHandler::ChangeBackgroundColors(float R, float G, float B)
{
	BGColor_R = R;
	BGColor_G = G;
	BGColor_B = B;
}