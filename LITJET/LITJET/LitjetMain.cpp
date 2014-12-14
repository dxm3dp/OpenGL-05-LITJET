
#include "../HeadFile/gltools.h"
#include "../HeadFile/math3d.h"

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

// ������Ⱦ״̬
void SetupRC()
{
	// ������Ȳ���
	glEnable(GL_DEPTH_TEST);	
	// ������ʱ�뻷�ƵĶ����Ϊ����
	glFrontFace(GL_CCW);
	// ���ñ����޳�
	glEnable(GL_CULL_FACE);
	// ------------���ù��ռ���-----------------------
	glEnable(GL_LIGHTING);
	// ָ��������ǿ�ȣ�RGBA��
	GLfloat ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// ָ��ɢ���ǿ�ȣ�RGBA��
	GLfloat diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	// ָ�������ǿ�ȣ�RGBA��
	GLfloat specularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// ָ�����ϵľ���ⷴ������
	GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// ���ù�Դ0�Ļ�����ɷ�
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	// ���ù�Դ0��ɢ���ɷ�
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	// ���ù�Դ0�ľ����ɷ�
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	// ���ù�Դ0
	glEnable(GL_LIGHT0);
	// ������ɫ׷��
	glEnable(GL_COLOR_MATERIAL);
	// ���ö��������Ļ������ɢ���������ԣ�׷��glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// ���ö��������ľ�����������
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	// ָ������ָ��
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	// ָ�����ɫ
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
	// ���߹淶��
	glEnable(GL_NORMALIZE);
}

// ���Ʒɻ�ģ��
void RenderPlane()
{
	M3DVector3f vNormal;	
	glColor3ub(128, 128, 128);
	glBegin(GL_TRIANGLES);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 60.0f);
		glVertex3f(-15.0f, 0.0f, 30.0f);
		glVertex3f(15.0f,0.0f,30.0f);

		{
			M3DVector3f vPoints[3] = {{ 15.0f, 0.0f,  30.0f},
			{ 0.0f,  15.0f, 30.0f},
			{ 0.0f,  0.0f,  60.0f}};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}	

		{
			M3DVector3f vPoints[3] = {{ 0.0f, 0.0f, 60.0f },
			{ 0.0f, 15.0f, 30.0f },
			{ -15.0f, 0.0f, 30.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ -15.0f, 0.0f, 30.0f },
			{ 0.0f, 15.0f, 30.0f },
			{ 0.0f, 0.0f, -56.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 0.0f, 0.0f, -56.0f },
			{ 0.0f, 15.0f, 30.0f },
			{ 15.0f,0.0f,30.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(15.0f,0.0f,30.0f);
		glVertex3f(-15.0f, 0.0f, 30.0f);
		glVertex3f(0.0f, 0.0f, -56.0f);

		{
			M3DVector3f vPoints[3] = {{ 0.0f,2.0f,27.0f },
			{ -60.0f, 2.0f, -8.0f },
			{ 60.0f, 2.0f, -8.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 60.0f, 2.0f, -8.0f},
			{0.0f, 7.0f, -8.0f},
			{0.0f,2.0f,27.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{60.0f, 2.0f, -8.0f},
			{-60.0f, 2.0f, -8.0f},
			{0.0f,7.0f,-8.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{0.0f,2.0f,27.0f},
			{0.0f, 7.0f, -8.0f},
			{-60.0f, 2.0f, -8.0f}};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}
	
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-30.0f, -0.50f, -57.0f);
		glVertex3f(30.0f, -0.50f, -57.0f);
		glVertex3f(0.0f,-0.50f,-40.0f);

		{
			M3DVector3f vPoints[3] = {{ 0.0f,-0.5f,-40.0f },
			{30.0f, -0.5f, -57.0f},
			{0.0f, 4.0f, -57.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 0.0f, 4.0f, -57.0f },
			{ -30.0f, -0.5f, -57.0f },
			{ 0.0f,-0.5f,-40.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 30.0f,-0.5f,-57.0f },
			{ -30.0f, -0.5f, -57.0f },
			{ 0.0f, 4.0f, -57.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 0.0f,0.5f,-40.0f },
			{ 3.0f, 0.5f, -57.0f },
			{ 0.0f, 25.0f, -65.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 0.0f, 25.0f, -65.0f },
			{ -3.0f, 0.5f, -57.0f},
			{ 0.0f,0.5f,-40.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

		{
			M3DVector3f vPoints[3] = {{ 3.0f,0.5f,-57.0f },
			{ -3.0f, 0.5f, -57.0f },
			{ 0.0f, 25.0f, -65.0f }};

			m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
			glNormal3fv(vNormal);
			glVertex3fv(vPoints[0]);
			glVertex3fv(vPoints[1]);
			glVertex3fv(vPoints[2]);
		}

	glEnd();
}

// ���Ƴ���
void RenderScene()
{
	// �����ɫ����������Ȼ�����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �������״̬
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	// ���ƶ���ηɻ�ģ��
	RenderPlane();
	// ��������������ʾ����
	glutSwapBuffers();
}

// ���ڴ�С�ı�ʱ�Ĵ���
void ChangeSize(int w, int h)
{
	GLfloat nRange = 80.0f;
	// �����0
	if(h == 0)
		h = 1;

	// �����ӿڴ�С
	glViewport(0, 0, w, h);
	// ����ͶӰ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// ���òü�����
	GLfloat fAspect = (GLfloat)w/(GLfloat)h;
	gluPerspective(45.0f, fAspect, 1.0f, 225.0f);
	// ����ģ����ͼ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// ָ����Դ��λ��
	GLfloat lightPos[] = {-50.0f, 50.0f, 100.0f, 1.0f};
	// ���ù�Դ0��λ��
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0.0f, 0.0f, -150.0f);
}

// ������Ӧ�Ĵ���
void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot-= 2.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 2.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 2.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 2.0f;

	if(key > 356.0f)
		xRot = 0.0f;

	if(key < -1.0f)
		xRot = 355.0f;

	if(key > 356.0f)
		yRot = 0.0f;

	if(key < -1.0f)
		yRot = 355.0f;

	// ˢ�´���
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("LitJet Demo");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	SetupRC();

	glutMainLoop();

	return 0;
}