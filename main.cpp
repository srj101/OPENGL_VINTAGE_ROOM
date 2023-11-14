#include <windows.h>
#include <GL/glut.h>
#define PI 3.141592653589793
#include<math.h>
#include <stdio.h>
#include <GL/gl.h>
#include <vector>

GLfloat p=10.0;

void init(void)
{
glClearColor(184.0/255.0,233.0/255.0,148.0/255.0,1.0); //GLfloat

//glclear to clear the color buffers
glMatrixMode(GL_PROJECTION); // To specify which matrix

//applies subsequent matrix to projecton matrix stack
glLoadIdentity();
glOrtho(-800.0, 800.0, -600.0, 600.0, -1.0, 1.0);
//gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic

//an orthographic matrix 2D= left right,bottom,top

}
void color(GLfloat r,GLfloat g,GLfloat b){
    glColor3f(r/255.0,g/255.0,b/255.0);
}

void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void circle(GLfloat cx,GLfloat cy, GLfloat rx, GLfloat ry){

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for( int i=0;i<=101;i++){
        GLfloat angle = 2.0f*PI*(i/100.0);
        GLfloat x = rx*cosf(angle);
        GLfloat y = ry*sinf(angle);

        glVertex2f(x+cx,y+cy);
    }

     glEnd();
}

void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y); //top left
    glVertex2f(x + width, y); //top right
    glVertex2f(x + width, y + height); //bottom right
    glVertex2f(x, y + height); //bottom left
    glEnd();
}
void drawBook(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2,GLfloat x3, GLfloat y3,GLfloat x4, GLfloat y4) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}


void drawBezierCurve(GLfloat p0[2], GLfloat p1[2], GLfloat p2[2], GLfloat p3[2]) {
    glBegin(GL_TRIANGLE_FAN);
    for (float t = 0; t <= 1; t += 0.01) {
        GLfloat point[2];
        point[0] = pow((1 - t), 3) * p0[0] + 3 * pow((1 - t), 2) * t * p1[0] + 3 * (1 - t) * pow(t, 2) * p2[0] + pow(t, 3) * p3[0];
        point[1] = pow((1 - t), 3) * p0[1] + 3 * pow((1 - t), 2) * t * p1[1] + 3 * (1 - t) * pow(t, 2) * p2[1] + pow(t, 3) * p3[1];
        glVertex2f(point[0], point[1]);
    }
    glEnd();
}

void lampcap() {
    GLfloat p0[2] = {-750, 100};
    GLfloat p1[2] = {-700, 500};
    GLfloat p2[2] = {-550, 500};
    GLfloat p3[2] = {-500, 100};

    drawBezierCurve(p0, p1, p2, p3);
}

void lampstand() {
    drawRectangle(-635,100,20,-500);

    GLfloat p0[2] = {-650, -450};
    GLfloat p1[2] = {-630, -380}; // Control point
    GLfloat p2[2] = {-620, -380}; // Control point
    GLfloat p3[2] = {-600, -450};

    drawBezierCurve(p0, p1, p2, p3);

}

void lampswitch(GLfloat p){
    drawRectangle(-570,100,5,-250-p);
    color(183,21,64);
    circle(-567,-150-p,10,30);
}

void lamp(GLfloat p) {
    color(227+p,121+p*15,43+p*15);
    lampcap();
    color(163,203,56);
    lampstand();
    color(229,80,57);
    lampswitch(p);
}

void half_circle(GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    // Change the range of i to only loop through half of the circle
    for(int i=0; i<=50; i++){
        GLfloat angle = 2.0f * 3.1416f * (i/100.0);
        GLfloat x = rx * cosf(angle);
        GLfloat y = ry * sinf(angle);

        glVertex2f(x+cx, -y+cy);
    }

    glEnd();
}

void fruits(){


    color(235,77,75);
    circle(-390,-225,16,14 );

    color(253,114,114);
    circle(-350,-220,10,10);

    color(106,176,76);
    circle(-370,-225,15,12);

    color(249,202,36);
    circle(-340,-222,15,16);
}

void bowl(){
    //fruits
    fruits();

    color(245,246,247);
    circle(-365,-230,60,5);

    color(239,128,176);
    half_circle(-365,-230,60,30);
}

void sofa(){
    // top
    color(112,111,211);
    drawBook(-480,-250,-365,-220,-250,-250,-365,-280);
    //left
    color(64,64,122);
    drawBook(-365,-280,-480,-250,-480,-420,-365,-450);
    //right
    color(99,99,151);
    drawBook(-365,-280,-365,-450,-250,-420,-250,-250);

    //Bowl
    bowl();
}

void triangle(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3){
    glBegin(GL_POLYGON);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glEnd();
}

void flowerstand(){
    color(140,122,230);
    triangle(-50,-450,-20,-450,-35,-420);
    circle(-35,-370,10,50);

    color(156,136,255);
    circle(-35,-310,10,10);
    circle(-35,-290,10,10);
    circle(-35,-270,10,10);

}

void flowertablesurface(){
    color(130,88,159);
    circle(-35,-250,150,10);
}

void tob(){
    color(126,214,223);
    circle(-35,-200,30,60);
    drawRectangle(-50,-120,30,-60);
}

void flowers(){
    color(114,95,83);
    drawLine(-35,-120,-75,-70);
    drawLine(-35,-120,10,-70);
    drawLine(-35,-120,-35,-65);

    color(255,94,87);
    circle(-38,-55,10,10);
    circle(-78,-60,10,10);
    circle(10,-60,10,10);
}



void flowerverse(){
    tob();
    flowerstand();
    flowertablesurface();

    flowers();
}

void tableStandleft(){
    glBegin(GL_POLYGON);
        glVertex2f(220,-370);
        glVertex2f(250,-370);
        glVertex2f(210,-450);
        glVertex2f(200,-450);
    glEnd();
}
void tableStandright(){
    glBegin(GL_POLYGON);
        glVertex2f(680,-370);
        glVertex2f(650,-370);
        glVertex2f(690,-450);
        glVertex2f(700,-450);
    glEnd();
}

void borderRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {

    drawLine(x, y,x + width, y);

    drawLine(x + width, y,x + width, y + height);

    drawLine(x + width, y + height,x, y + height);

    drawLine(x, y + height,x, y);

}

void drawers(){
    color(255,255,255);
    borderRectangle(220,-140,200,-80);

    color(255,255,255);
    borderRectangle(220,-250,200,-80);
}




void tableGap(){
    drawRectangle(450,-140,230,-190);
}

void tablePan(){
    half_circle(610,-300,60,30);
}

void tableCup(){
    color(126,214,223);
    triangle(510,-180,500,-330,520,-330);
    half_circle(510,-185,40,35);
}

void tableTobFlowers(){

    color(114,95,83);
    drawLine(630,-10,675,15);
    drawLine(630,-10,630,100);
    drawLine(630,-10,585,15);

    drawLine(630,15,585,50);
    drawLine(630,15,675,50);

    drawLine(630,40,585,90);
    drawLine(630,40,675,90);

    color(255,168,1);
    circle(585,15,10,10);
    circle(630,100,10,10);
    circle(675,15,10,10);
    circle(585,50,10,10);
    circle(585,90,10,10);
    circle(675,50,10,10);
    circle(675,90,10,10);

}

void tableTob(){
    color(163,203,56);
    half_circle(630,-10,40,150);
    tableTobFlowers();
}

void table(){

    tableTob();

    color(104,109,224);
    drawRectangle(200,-120,500,-250);

    color(87,88,187);
    tableStandleft();
    tableStandright();

    drawers();

    color(184,233,148);
    tableGap();

    color(253,167,223);
    tablePan();

    tableCup();


}

void flowerVerseShelf(){


    color(68,189,50);
    circle(50,340,10,60);
    color(196,229,56);
    circle(25,340,10,40);
    color(163,203,56);
    circle(70,340,10,30);



    color(227,121,43);
    half_circle(50,320,40,60);
}

void bottomShelfBooks(){
    color(114,95,83);
    drawBook(250,270,270,380,260,390,240,285);

    color(224,199,143);
    drawRectangle(200,350,15,-80);

    color(224,199,143);
    drawRectangle(220,380,15,-110);

    color(227,121,43);
    drawRectangle(290,385,20,-115);

    color(227,121,43);
    drawRectangle(320,385,20,-115);
}

void topShelfBooks(){
    color(224,199,143);
    drawBook(280,420,285,430,260,530,255,520);

    color(224,199,143);
    drawRectangle(135,500,30,-80);

    color(113,95,83);
    drawRectangle(175,520,20,-100);

    color(113,95,83);
    drawRectangle(200,520,20,-100);

    color(113,95,83);
    drawRectangle(225,520,20,-100);

    color(224,199,143);
    drawRectangle(300,510,25,-90);

    color(227,121,43);
    drawRectangle(330,500,37,-80);

    color(227,121,43);
    drawRectangle(380,500,37,-80);

    color(113,95,83);
    drawRectangle(430,520,10,-100);
}

void shelfbottom(){
    flowerVerseShelf();

    color(1,171,157);
    drawRectangle(0,250,400,20);

    bottomShelfBooks();
}

void shelftop(){
    color(1,171,157);
    drawRectangle(100,400,400,20);

    topShelfBooks();
}

void shelf(){
    shelfbottom();
    shelftop();
}

void floorLines(){
    color(236,240,241);
    // Vertical
    drawLine(-500,-350,-600,-600);
    drawLine(-300,-350,-350,-600);
    drawLine(-100,-350,-130,-600);
    drawLine(100,-350,130,-600);
    drawLine(300,-350,350,-600);
    drawLine(500,-350,600,-600);

    // Horizontal
    drawLine(-800,-400,800,-400);
    drawLine(-800,-450,800,-450);
    drawLine(-800,-500,800,-500);
    drawLine(-800,-550,800,-550);
}

void floor(){
    color(96,163,188);
    drawBook(-800,-600,-650,-350,750,-350,950,-600);

    floorLines();
}


void leftwall(){

    drawBook(-650,-350,-650,500,-800,600,-800,-600);
}
void rightwall(){

    drawBook(750,-350,750,500,800,600,900,-580);
}

void ceiling(){

    drawBook(-650,500,750,500,800,600,-800,600);
}

void room(){
    floor();

    color(120,224,143);
    leftwall();

    color(120,224,143);
    rightwall();

    color(189,197,129);
    ceiling();
}


void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);

if(p<=10)
    p=p+0.005;
else
    p=-10;



room();

lamp(p);

sofa();

flowerverse();

table();

shelf();

glutPostRedisplay();


glutSwapBuffers();
}



int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
glutInitWindowPosition(100,200);
glutInitWindowSize(800,600);
glutCreateWindow("Computer Graphics Project | 201-15-3117 | 57-D");
init();
glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}
