#include "CCylinder.h"
#include "CCircle.h"

// cylinder is with circle in xy with radius=1 and depth = 1 (between 0 to 1)
CCylinder::CCylinder(void)
{
	CCircle circle, circle2;
	circle.MovePolygonCenter(0,0,1);
	circle2.MovePolygonCenter(0, 0, 0);

	circle.SetPolygonColor(60,0,0);
	
	CPolygon part_of_cylinder(4);

	SetNumberOfPolygons(circle.GetNumberOfPoints()+2);

	for (int point_index=0; point_index<circle.GetNumberOfPoints(); point_index++)
	{
		int next_point_index = point_index+1;
		if(next_point_index==30)
		{
			next_point_index=0;
		}
		
		part_of_cylinder.SetOnePoint(0,circle.GetPoint(next_point_index));
		part_of_cylinder.SetOnePoint(1,circle.GetPoint(point_index));
		part_of_cylinder.SetOnePoint(2,circle2.GetPoint(point_index));
		part_of_cylinder.SetOnePoint(3,circle2.GetPoint(next_point_index));
		SetOnePolygon(point_index, part_of_cylinder);
	}

	SetOnePolygon(circle.GetNumberOfPoints(), circle);
	SetOnePolygon(circle.GetNumberOfPoints()+1, circle2);
}
