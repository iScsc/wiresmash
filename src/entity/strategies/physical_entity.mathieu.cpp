class PhysicalEntity {

private :
    PhysicsProp phxProp;


public :
    /*
    * Collisionner, structure defining the collision between 2 entities
    */
    struct Collisionner {
        Entity* touching;
        Entity* touched;
        std::vector<int> intricate;
    };

    typedef struct Collisionner Collisionner;

    /*
    * Physics properties structure of a given entity
    */
    struct PhysicsProp {
        std::vector<int> position;
        std::vector<int> speed;
    }

    typedef struct PhysicsProp PhysicsProp;

    /*
    * Inverts the speed
    */
    void invertSpeed() {
        phxProp.speed[0] *= -1;
        phxProp.speed[1] *= -1;
    }

    /**
     * Correts the collided entities' position and speed 
     */
    static void correctionUpdate(std::vector<Collisionner> collisionners)
    {
        for (Collisionner col : collisionners) {
            // TODO HELLO GREGORY
            Entity ett1 = *col.touching;
            Entity ett2 = *col.touched;
            std::vector<int> intr = col.intricate;
            //TODO implement bouncyness later
            // unsigned double b1,b2; //bouncyness
            // b1 = ett1.bouncyness;
            // b2 = ett2.bouncyness;
            const unsigned int m1 = ett1.mass;
            const unsigned int m2 = ett2.mass;
            const double ratio = m2/(m1 + m2);
            // Inherited from SFML transformable
            ett1.move(floor( ratio     *intr[0]),floor( ratio     *intr[1]));
            ett2.move(floor((ratio - 1)*intr[0]),floor((ratio - 1)*intr[1]));

            //Reversing speed
            ett1.invertSpeed();
            ett2.invertSpeed();
        }
    }
}
