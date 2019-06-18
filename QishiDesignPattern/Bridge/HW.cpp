#include <string>
using namespace std;
struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct Shape
{
    string name;
    const Renderer& r;
    Shape(const Renderer& r) : r{r}{}
    string str() const
    {
        return "Drawing " + name + r.what_to_render_as();
    }
};

struct Triangle : Shape
{
    Triangle(const Renderer& r) : Shape{r}{name = "Circle";}
    
};

struct Square : Shape
{
    Square(const Renderer& r) : Shape{r}{name = "Square";}
    
};

struct VectorRenderer : Renderer
{
    string what_to_render_as() const override
    {
        return " as lines";
    }
};

struct RasterSquare : Renderer
{
    string what_to_render_as() const override
    {
        return " as pixels";
    }
};
