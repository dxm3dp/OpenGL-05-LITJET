
#include "../HeadFile/gltools.h"
#include "../HeadFile/math3d.h"

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

// 设置渲染状态
void SetupRC()
{
	// 启用深度测试
	glEnable(GL_DEPTH_TEST);	
	// 设置逆时针环绕的多边形为正面
	glFrontFace(GL_CCW);
	// 启用背面剔除
	glEnable(GL_CULL_FACE);
	// ------------启用光照计算-----------------------
	glEnable(GL_LIGHTING);
	// 指定环境光强度（RGBA）
	GLfloat ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// 指定散射光强度（RGBA）
	GLfloat diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	// 指定镜面光强度（RGBA）
	GLfloat specularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// 指定材料的镜面光反射属性
	GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// 设置光源0的环境光成分
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	// 设置光源0的散射光成分
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	// 设置光源0的镜面光成分
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	// 启用光源0
	glEnable(GL_LIGHT0);
	// 启用颜色追踪
	glEnable(GL_COLOR_MATERIAL);
	// 设置多边形正面的环境光和散射光材料属性，追踪glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// 设置多边形正面的镜面光材料属性
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	// 指定镜面指数
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	// 指定清除色
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
	// 法线规范化
	glEnable(GL_NORMALIZE);
}

// 绘制飞机模型
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

// 绘制场景
void RenderScene()
{
	// 清除颜色缓冲区和深度缓冲区
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 保存矩阵状态
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	// 绘制多边形飞机模型
	RenderPlane();
	// 交换缓冲区，显示画面
	glutSwapBuffers();
}

// 窗口大小改变时的处理
void ChangeSize(int w, int h)
{
	GLfloat nRange = 80.0f;
	// 避免除0
	if(h == 0)
		h = 1;

	// 设置视口大小
	glViewport(0, 0, w, h);
	// 重置投影矩阵
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// 设置裁剪区域
	GLfloat fAspect = (GLfloat)w/(GLfloat)h;
	gluPerspective(45.0f, fAspect, 1.0f, 225.0f);
	// 重置模型视图矩阵
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// 指定光源的位置
	GLfloat lightPos[] = {-50.0f, 50.0f, 100.0f, 1.0f};
	// 设置光源0的位置
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0.0f, 0.0f, -150.0f);
}

// 按键响应的处理
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

	// 刷新窗口
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