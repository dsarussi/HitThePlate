#include "CModel.h"

#pragma region CONSTRUCTORs & DESTRUCTOR
CModel::CModel()
{
	_num_of_polygons = 2;
	_polygons_array = new CPolygon [_num_of_polygons];
}

CModel::CModel(int num_of_polygons)
{
		_num_of_polygons= num_of_polygons;
	_polygons_array = new CPolygon [_num_of_polygons];
}

CModel::CModel(const CModel& model)
{
	_num_of_polygons = model._num_of_polygons;
	_polygons_array = new CPolygon[_num_of_polygons];
	for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].DuplicatePolygon(model._polygons_array[i]);
}

CModel::~CModel()
{
	delete[] _polygons_array;
}
#pragma endregion

#pragma region Setting model properties
void CModel::SetNumberOfPolygons(int num_of_polygons)
{
	delete[] _polygons_array;
	_num_of_polygons = num_of_polygons;	
	_polygons_array = new CPolygon [_num_of_polygons];
}

void CModel::SetModelColor(Color color_component, double color_value)
{
	for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].SetPolygonColor(color_component, color_value);
}

void CModel::SetModelColor(double red_component, double green_component, double blue_component)
{
		for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].SetPolygonColor(red_component,green_component,blue_component);
}	
#pragma endregion

#pragma region Setting one polygon properties
void CModel::SetOnePolygon(int polygon_index, CPolygon polygon)
{
	_polygons_array[polygon_index].DuplicatePolygon(polygon);
}

void CModel::SetOnePolygonColor(int polygon_index, Color color_component, double color_value)
{
		_polygons_array[polygon_index].SetPolygonColor(color_component,color_value);
}

void CModel::SetOnePolygonColor(int polygon_index, double red_component, double green_component, double blue_component)
{
	_polygons_array[polygon_index].SetPolygonColor(red_component,green_component,blue_component);
}
#pragma endregion

#pragma region Move model functions
void CModel::MoveModel(Axis axis, double move_value)
{
	for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].MovePolygon(axis,move_value);

}

void CModel::MoveModel(double x_move, double y_move,double z_move)
{
	for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].MovePolygon(x_move,y_move,z_move);
}

void CModel::MoveModel(CPoint point_move)
{
	for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].MovePolygon(point_move);
}

void CModel::MoveModelCenter(Axis axis, double coordinate_value)
{
	CPoint p = GetModelCenter();
	MoveModel(axis, coordinate_value - p.GetCoordinate(axis));
}

void CModel::MoveModelCenter(double x_coordinate, double y_coordinate, double z_coordinate)
{
	CPoint p = GetModelCenter();
	p.ScalePoint(-1, -1, -1);
	MoveModel(p);
	MoveModel(x_coordinate, y_coordinate, z_coordinate);
}

void CModel::MoveModelCenter(CPoint point_coordinate)
{
	CPoint p = GetModelCenter();
	p.ScalePoint(-1, -1, -1);
	MoveModel(p);
	MoveModel(point_coordinate);
}
#pragma endregion

#pragma region Scale model functions
void CModel::ScaleModel(Axis axis, double scale_ratio)
{
		for (int i = 0; i < _num_of_polygons; i++) 
			_polygons_array[i].ScalePolygon(axis,scale_ratio);
}

void CModel::ScaleModel(double x_ratio, double y_ratio, double z_ratio)
{
			for (int i = 0; i < _num_of_polygons; i++) 
				_polygons_array[i].ScalePolygon(x_ratio , y_ratio , z_ratio);
}

void CModel::ScaleSelfModel(Axis axis, double scale_ratio)
{
	CPoint model_center = GetModelCenter();
	model_center.ScalePoint(-1, -1, -1);
	MoveModel(model_center);
	model_center.ScalePoint(-1, -1, -1);
	ScaleModel(axis, scale_ratio);
	MoveModel(model_center);
}

void CModel::ScaleSelfModel(double x_ratio, double y_ratio, double z_ratio)
{
	CPoint model_center = GetModelCenter();
	model_center.ScalePoint(-1, -1, -1);
	MoveModel(model_center);
	model_center.ScalePoint(-1, -1, -1);
	ScaleModel(x_ratio,y_ratio,z_ratio);
	MoveModel(model_center);
}
#pragma endregion

#pragma region Rotate model functions
void CModel::RotateModel(Axis axis, double rotate_value)
{
	for (int i = 0; i < _num_of_polygons; i++) 
		_polygons_array[i].RotatePolygon(axis,rotate_value);
}

void CModel::RotateSelfModel(Axis axis, double rotate_value)
{
	CPoint model_center = GetModelCenter();
	model_center.ScalePoint(-1, -1, -1);
	MoveModel(model_center);
	model_center.ScalePoint(-1, -1, -1);
	RotateModel(axis, rotate_value);
	MoveModel(model_center);
}
#pragma endregion

#pragma region Draw model function
void CModel::DrawModel()
{
	for (int i = 0; i < _num_of_polygons; i++)
		_polygons_array[i].DrawPolygon();
}
#pragma endregion

#pragma region Get functions
CPolygon CModel::GetPolygon(int polygon_index)
{
	return _polygons_array[polygon_index];
}

CPoint CModel::GetModelCenter()
{
	CPoint sum(0,0,0);
		for (int i = 0; i < _num_of_polygons; i++)
			sum.MovePoint(_polygons_array[i].GetPolygonCenter());
	 double scale_ratio = 1.0/_num_of_polygons;
	sum.ScalePoint(scale_ratio, scale_ratio, scale_ratio);
	return sum;
}

int CModel::GetNumberOfPolygons()
{
	return _num_of_polygons;
}
#pragma endregion