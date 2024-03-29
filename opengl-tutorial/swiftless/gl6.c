#include <GL/glew.h>		// Include the GLEW header file
#include <GL/glut.h>		// Include the GLUT header file
#include <stdio.h>

int keyStates[256] = {0};

void KeyOperations(void)
{
	if(keyStates['a'])
	{
		printf("key a press \n");
	}
}

void display(void)
{
	KeyOperations();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// Clear the background of our window to red  
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the colour buffer (more buffers later on)  
	glLoadIdentity();	// Load the Identity Matrix to reset our drawing locations  
	glTranslatef(0.0f, 0.0f, -5.0f);
	//glut cube
	//glutWireCube(2.0f);
	//glutSolidCube(2.0f);
	//glutWireSphere(2.0f, 50, 50);
	//glutSolidShpere(2.0f, 50, 50);
	//glutWireCone(2.0f, 1.0f, 10, 10);
	//glutSolidCone(2.0f, 1.0f, 10, 10);
	//glutWireTorus(0.5f, 1.0f, 50, 50);
	//glutSolidTorus(0.5f, 1.0f, 50, 50);
	//glutWireTeapot(1.5f);
	glutSolidTeapot(1.5f);
	glFlush();		// Flush the OpenGL buffers to the window  
}

void reshape(int width, int height)
{
	/* Set our viewport to the size of our window  */
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	/* Switch to the projection matrix so that we can manipulate how our scene is viewed  */
	glMatrixMode(GL_PROJECTION);
	/*Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)*/
	glLoadIdentity();
	/*Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes*/
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
	/* Switch back to the model view matrix, so that we can start drawing shapes correctly */
	glMatrixMode(GL_MODELVIEW);
}

void keyPressd(unsigned char key, int x, int y)
{
	keyStates[key] = 1;
}

void keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = 0;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);	// Initialize GLUT  
	glutInitDisplayMode(GLUT_SINGLE);	// Set up a basic display buffer (only single buffered for now)  
	glutInitWindowSize(500, 500);	// Set the width and height of the window  
	glutInitWindowPosition(100, 100);	// Set the position of the window  
	glutCreateWindow("Your first OpenGL Window");	// Set the title for the window  

	glutDisplayFunc(display);	// Tell GLUT to use the method "display" for rendering  
	glutReshapeFunc(reshape);
	
	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events
	
	glutMainLoop();		// Enter GLUT's main loop  
}
