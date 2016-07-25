#include "Image.h"

//Image Constructor
Image::Image(int width_, int height_)
	:_width(width_), _height(height_)
{
	_buffer = (Color *)malloc(_width * _height * sizeof(Color));
	Clear(Color(1.0));
}

//Image Destructor
Image::~Image()
{
	free(_buffer);
}

//Write to PPM file format
void Image::WritePPM(const char *outfile)
{
	FILE *file;
	file = fopen(outfile, "w");
	fprintf(file, "P3\n%i %i\n255\n", _width, _height);

	for (int Y = 0; Y < _height; ++Y)
	{
		for (int X = 0; X < _width; ++X)
		{
			Color temp = _buffer[Y * _width + X];
			unsigned char ir = unsigned char(temp.r * 255.99);
			unsigned char ig = unsigned char(temp.g * 255.99);
			unsigned char ib = unsigned char(temp.b * 255.99);
			fprintf(file, "%u %u %u ", ir, ig, ib);
		}
	}
	fclose(file);
}

void Image::Clear(Color& color)
{
	for (int Y = 0; Y < _height; ++Y)
	{
		for (int X = 0; X < _width; ++X)
		{
			_buffer[Y * _width + X] = color;
		}
	}
}

//Get the Color in the buffer
Color Image::pixel(int x, int y)
{
	return _buffer[_width * y + x];
}

//Set the Color in the buffer
void Image::pixel(int x, int y, Color c)
{
	_buffer[_width * y + x] = c;
}

//Get the Image width
int Image::width() const
{
	return _width;
}

//Get the Image height
int Image::height() const
{
	return _height;
}