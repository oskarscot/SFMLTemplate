#include "window/Application.h"

int main(){
    const TerClone::ApplicationWindowSpec spec{1280, 720, "SFML works!"};
    TerClone::Application app(spec);
    app.Run();
    return 0;
}
