#ifndef RASHNAWA_ENTITY_H
#define RASHNAWA_ENTITY_H


class Entity {
private:
    float _x;
    float _y;
public:
    Entity(float x, float y);

    virtual ~Entity();

    [[nodiscard]] float getX() const;

    void setX(float x);

    [[nodiscard]] float getY() const;

    void setY(float y);
};


#endif //RASHNAWA_ENTITY_H
