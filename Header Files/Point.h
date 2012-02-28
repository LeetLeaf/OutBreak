#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point(int x,int y);

		int getX(){return dot[0];};
		int getY(){return dot[1];};
	
	private:

		int dot[2];

};


#endif