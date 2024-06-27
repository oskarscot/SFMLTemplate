#pragma once

#include "window/Application.h"

namespace TerClone {

    class MainApplication : Application
    {
    public:
        explicit MainApplication(const ApplicationWindowSpec &spec);
    protected:
        void Update(sf::Time deltaTime) override;
        void Render() override;

    };

}