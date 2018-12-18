# include <iostream>
# include <stdlib.h>  
# include <time.h>
# include <fstream>
# include <iostream>

# define SPACE_X 30
# define SPACE_Y 40
# define MAX_LENGTH 3
# define BOXOFNUMBER 10

using namespace std;


class Coord {

	private:
		int x;
		int y;

	public:
		Coord();

		Coord(double x, double y);
		
		void setCoord(double x, double y);
		
		double getCoordX();

		double getCoordY();

		~Coord();
};

class Box {
	private:
		int width;
		int height;
		int density;
		int centerPointX, centerPointY;
		int randomCoordPointX, randomCoordPointY;
		int mass;
		Coord coord;
		
	public:
		Box();

		void setBox(double x, double y);

		double getBoxX();

		double getBoxY();

		void setBoxWidth(double w);

		void setBoxHeight(double h);

		double getBoxWidth();

		double getBoxHeight();

		void setCenterPointX(double c_px);

		void setCenterPointY(double c_py);

		double getCenterPointX();

		double getCenterPointY();
		
		void setBoxDensity(double d);
		
		double getBoxDensity();

		double getMass();
		
		void randomWidth();

		void randomHeight();

		void randomPointX();
		
		void randomPointY();

		bool placeBox(double space[][SPACE_Y]);
		
		void printBoxCoordinates();

		~Box();
};

class Space {
	private:
		int width;
		int height;
		Box box;

	public:
		double space[SPACE_X][SPACE_Y];
		
		Space();

		double getWidth();

		double getHeight();

		double getNumOfBoxes();

		double getSpaceArea();

		void setSpaceIn();

		void printCenterOfMass();

		~Space();
};

Coord::Coord() { }

Coord::Coord(double x, double y) {
	this -> x = x ;
	this -> y = y ;
}

void Coord::setCoord(double x, double y) {
	this -> x = x ;
	this -> y = y ;
}

double Coord::getCoordX() {
	return x;
}

double Coord::getCoordY() {
	return y;
}

Coord::~Coord() { }

Box::Box() { }

void Box::setBox(double x, double y) {
	if (x < 0 && y < 0)
		coord.setCoord(0, 0);
	else
		coord.setCoord(x, y);
}

double Box::getBoxX() {
	return coord.getCoordX();
}

double Box::getBoxY() {
	return coord.getCoordY();
}

void Box::setBoxWidth(double w) {
	if (w <= 0)
		width = 1;
	else
		width = w;
}

void Box::setBoxHeight(double h) {
	if (h <= 0)
		height = 1;
	else
		height = h;
}

double Box::getBoxWidth() {
	return width;
}

double Box::getBoxHeight() {
	return height;
}

void Box::setCenterPointX(double c_px) {
	centerPointX = c_px;
}

void Box::setCenterPointY(double c_py) {
	centerPointY = c_py;
}

double Box::getCenterPointX() {
	return centerPointX;
}

double Box::getCenterPointY() {
	return centerPointY;
}

void Box::setBoxDensity(double d) {
	if (d <= 0)
		density = 1;
	else
		density = d;
}

double Box::getBoxDensity() {
	return density;
}

double Box::getMass() {
	
	return width * height * density;
}

void Box::randomWidth() {
	width = rand() % MAX_LENGTH + 1;
}

void Box::randomHeight() {
	height = rand() % MAX_LENGTH + 1;
}

void Box::randomPointX() {
	randomCoordPointX = rand() % SPACE_X;	
}

void Box::randomPointY() {
	randomCoordPointY = rand() % SPACE_Y;	
}

bool Box::placeBox(double space[][SPACE_Y]){
	if (randomCoordPointY + height < SPACE_Y && randomCoordPointX + width <SPACE_X)
	{
		bool is_intersection = false;
		for(int i = randomCoordPointY; i < randomCoordPointY + height; i++)
		{
			for(int j = randomCoordPointX; j < randomCoordPointX + width; j++)
			{
				if(space[i][j] == 1) is_intersection = true;
				space[i][j] = 1;
			}
		}

		if(!is_intersection) {
			centerPointX = randomCoordPointX + width / 2;
			centerPointY = randomCoordPointY + height / 2;
			return true;
		}
	}

	if (randomCoordPointY + height < SPACE_Y && randomCoordPointX - width >= 0)
	{
		bool is_intersection = false;
		for(int i = randomCoordPointY; i < randomCoordPointY + height; i++)
		{
			for(int j = randomCoordPointX; j > randomCoordPointX - width; j--)
			{
				if(space[i][j] == 1) is_intersection = true;
				space[i][j] = 1;
			}
		}

		if(!is_intersection) {
			centerPointX = randomCoordPointX - width / 2;
			centerPointY = randomCoordPointY + height / 2;
			return true;
		}
	}

	if (randomCoordPointY - height >= 0 && randomCoordPointX + width < SPACE_X)
	{
		bool is_intersection = false;
		for(int i = randomCoordPointY; i > randomCoordPointY - height; i--)
		{
			for(int j = randomCoordPointX; j < randomCoordPointX + width; j++)
			{
				if(space[i][j] == 1) is_intersection = true;
				space[i][j] = 1;
			}
		}

		if(!is_intersection) {
			centerPointX = randomCoordPointX + width / 2;
			centerPointY = randomCoordPointY - height / 2;
			return true;
		}
	}

	if (randomCoordPointY - height >= 0 && randomCoordPointX - width >= 0)
	{
		bool is_intersection = false;
		for(int i = randomCoordPointY; i > randomCoordPointY - height; i--)
		{
			for(int j = randomCoordPointX; j > randomCoordPointX - width; j--)
			{
				if(space[i][j] == 1) is_intersection = true;
				space[i][j] = 1;
			}
		}

		if(!is_intersection) {
			centerPointX = randomCoordPointX - width / 2;
			centerPointY = randomCoordPointY - height / 2;
			return true;
		}
	}

	return false;
}

void Box::printBoxCoordinates(){
	ofstream outfile;
	outfile.open("coord.txt", ios::app);

	cout    << "Kutunun Noktalari : "        << endl;
	cout    << "x1 : "  << randomCoordPointX << " x2 : " << (randomCoordPointX + width);
	outfile << "x1 : "  << randomCoordPointX << " x2 : " << (randomCoordPointX + width);
	cout    << "\ty1 : "<< randomCoordPointY << " y2 : " << (randomCoordPointY + height) << endl;
	outfile << "\ty1 : "<< randomCoordPointY << " y2 : " << (randomCoordPointY + height) << endl;

	outfile.close();
}

Box::~Box() { }

Space::Space() { }

double Space::getWidth() {
	return width;
}

double Space::getHeight() {
	return height;
}


double Space::getSpaceArea() {
	return SPACE_X * SPACE_Y;
}

void Space::setSpaceIn() {
	for(int i = 0; i <= SPACE_X; i++)
	{
		for(int j = 0; j <= SPACE_Y; j++)
		{
			space[i][j] = 0;
		}
	}
}

void Space::printCenterOfMass() {
	double massX, massY;
	massX = (box.getMass() * box.getCenterPointX()) / box.getMass();
	massY = (box.getMass() * box.getCenterPointY()) / box.getMass();
	//cout << "Center Of Mass  x : "<< massX << " y : "<< massY <<endl;
}

Space::~Space() { }

int main()
{
	Space s;
	srand(time(NULL));
	s.setSpaceIn();
	for (int l=0; l<=BOXOFNUMBER;l++)
	{
		if(SPACE_X <=0 || SPACE_Y <=0 || BOXOFNUMBER <=0 || MAX_LENGTH <= 0)
		{
			exit(0);
		}
		else
		{
			Box b;
			b.randomWidth();
			b.randomHeight();
			b.randomPointX();
			b.randomPointY();
			b.placeBox(s.space);
			b.printBoxCoordinates();
			s.printCenterOfMass();
		}
		
	}
	return 0;
}