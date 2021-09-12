#include <bangtal>
using namespace bangtal;

int main()
{
    auto scene1 = Scene::create("룸1", "Images/배경-1.png");
    auto scene2 = Scene::create("룸2", "Images/배경-2.png");


    auto door1 = Object::create("Images/문-오른쪽-닫힘.png", scene1, 800, 270);
    auto door2 = Object::create("Images/문-왼쪽-열림.png", scene2, 420, 290);
    auto door3 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 900, 280);
    door3->setScale(0.5f);

    auto open1 = false;
    auto open2 = true;
    auto key = Object::create("Images/열쇠.png", scene1, 600, 150);
    key->setScale(0.2f);

    key->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        key->pick();
        return true;
    });

    auto flowerpot_moved = false;
    auto flowerpot = Object::create("Images/화분.png", scene1, 550, 150);
    flowerpot->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
        if (flowerpot_moved == false) {
            if (action == MouseAction::MOUSE_DRAG_LEFT) {
                flowerpot->locate(scene1, 450, 150);
                flowerpot_moved = true;
            }
            else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
                flowerpot->locate(scene1, 650, 150);
                flowerpot_moved = true;
            }

        }
        return true;
        });

   
    door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (open1 == true) {
            scene2->enter();
        }
        else if (key->isHanded()) {
            door1->setImage("Images/문-오른쪽-열림.png");
            open1 = true;
        }
        return true;
        });

    door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (open1 == true) {
            scene1->enter();
        }
        return true;
        });

    door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        endGame();
        return true;
        });
    startGame(scene1);
}