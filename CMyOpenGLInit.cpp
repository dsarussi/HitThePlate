#include "CGameHandler.h"
#include "CMyOpenGLInit.h"
#include "glut.h"

CGameHandler MyGame;

void special(int key, int x, int y);

typedef unsigned char	ubyte;	

void specialkeys( int key, int x, int y );
void keyboard(unsigned char key, int x, int y);


void setOrthographicProjection()
{
	/* switch to projection mode */
	glMatrixMode(GL_PROJECTION);
	/* save previous matrix which contains the settings for the perspective projection */
	glPushMatrix();
	/* reset matrix */
	glLoadIdentity();
	/* set a 2D orthographic projection */
	gluOrtho2D(0, glutGet(GLUT_SCREEN_WIDTH), 0, glutGet(GLUT_SCREEN_HEIGHT));
	/* invert the y axis, down is positive */
	glScalef(1, -1, 1);
	/* move the origin from the bottom left corner to the upper left corner */
	glTranslatef(0, -glutGet(GLUT_SCREEN_HEIGHT), 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font, char *string)
{
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void renderSpacedBitmapString(float x, float y, int spacing, void *font, char *string)
{
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++)
	{
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c) + spacing;
	}
}


void renderVerticalBitmapString(float x, float y, int bitmapHeight, void *font, char *string)
{
	char *c;
	int i;
	for (c = string, i = 0; *c != '\0'; i++, c++)
	{
		glRasterPos2f(x, y+bitmapHeight*i);
		glutBitmapCharacter(font, *c);
	}
}


void MyDraw()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	glutPostRedisplay();
	
	glClearColor(MyGame.GetBeckgroundColorR(), MyGame.GetBeckgroundColorG(), MyGame.GetBeckgroundColorB(), 0);
	MyGame.DrawScene();	
	MyGame.LogicPart();
	
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	setOrthographicProjection();
	glLoadIdentity();
	
	MyGame.WriteText();
	
	resetPerspectiveProjection();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape( GLsizei width, GLsizei height )
{
	GLdouble    aspect;
	
	glViewport( 0, 0, width, height );
	
	/* compute aspect ratio */
	aspect = (GLdouble) width / (GLdouble) height;
	
	glMatrixMode( GL_PROJECTION );
	/* Reset world coordinates first ... */
	glLoadIdentity();
	
	/* Reset the viewing volume based on the new aspect ratio */
	gluPerspective( 45.0, aspect, 1.0, 300.0 );
	
	glMatrixMode( GL_MODELVIEW );
}

CMyOpenGLInit::CMyOpenGLInit(int argc, char* argv[])
{
	int x, y;
	
	MyGame.StartOfGame();
	
	glutInit(&argc, argv);
	x = glutGet(GLUT_SCREEN_WIDTH);
	y = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(x, y);
	glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
	glutCreateWindow("Computer Graphics Project");
	
	InitParameters();
		
	glutKeyboardFunc( keyboard );
	glutSpecialFunc( special );	
	glutReshapeFunc( reshape );
	glutDisplayFunc (MyDraw);
	glClearColor(MyGame.GetBeckgroundColorR(), MyGame.GetBeckgroundColorG(), MyGame.GetBeckgroundColorB(), 0);
	glutMainLoop();
}

void CMyOpenGLInit::InitParameters()
{
	/* enable the depth buffer */
	glEnable( GL_DEPTH_TEST );
	
	/* enable the face culling */
	glEnable( GL_CULL_FACE );
	
	/* Turn on the default light */
	glEnable( GL_LIGHT0 );
	glEnable( GL_LIGHTING );
	
	/* have OpenGL automatically normalize the normals, since we have lighting
	turned on and are scaling 	*/
	glEnable( GL_NORMALIZE );
	
	/* Enable fast material changes for diffuse material */
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	glEnable( GL_COLOR_MATERIAL );
}

void keyboard(unsigned char key, int x, int y)
{
	MyGame.KeyPressed(key);
    glutPostRedisplay();
}

void special(int key, int x, int y)
{
    MyGame.SpecialKeyPressed(key);
    glutPostRedisplay();
}

