#ifndef GROUND
#define GROUND

#include "math.h"

#include "vector2d.h"
#include "drawable.h"

/**
 * @author Mayencourt Louis
 * @date 2012
 * @version 1.0
 */
class Ground : public Drawable
{
private:
    int imageWidth, imageHeight;
//    GraphicsBitmap foregroundB;
//    GraphicsBitmap gameField = new GraphicsBitmap("/images/background1.png");

//    bool* boundary[][];

    /**
     * Optimized version of ground parsing for given coordinates
     *
     * @param startx
     * @param starty
     * @param width
     * @param height
     */
//    void parseGround(int startx, int starty, int width, int height) {
//        for (int i = startx; i < startx + width; i++) {
//            for (int j = starty; j < starty + height; j++) {
//                if (i >= imageWidth || i < 0)
//                    continue;
//                if (j >= imageHeight || j < 0)
//                    continue;

//                if (((foregroundB.getBufferedImage().getRGB(i, j) >> 24) & 0xff) == 0)
//                    boundary[i][j] = false;
//                else
//                    boundary[i][j] = true;
//            }
//        }
//    }

public:
    /**
     * An imageless constructor. This ground only has the screen borders as
     * limits.
     *
     * @param width
     * @param height
     */
    Ground(int width, int height) {
        imageWidth = width;
        imageHeight = height;

        // Load the background images
//        foregroundB = new GraphicsBitmap("/images/background0.png");

        // Create the ground boundary that is used for collisions
//        boundary = new bool[imageWidth][imageHeight];
//        parseGround(0, 0, imageWidth, imageHeight);
    }

    /**
     * Constructor with an image path Every non-transparent pixel is considered
     * an obstacle
     *
     * @param backgroundImagePath
     */
//    Ground(std::string backgroundImagePath) {
//        // Load the background images
//        foregroundB = new GraphicsBitmap(backgroundImagePath);

//        imageWidth = foregroundB.getWidth();
//        imageHeight = foregroundB.getHeight();

//        // Create the ground boundary that is used for collisions
//        boundary = new boolean[imageWidth][imageHeight];
//        parseGround(0, 0, imageWidth, imageHeight);
//    }

    /**
     * @param position of an object
     * @return -1 if not colliding, PI / 2 if bouncing against vertical wall or 0 if horizontal ground
     */
    double collidesGround(Vector2D* position) {

        if(position->x <= imageWidth && position->x >= 0 && position->y <= imageHeight)
        {
//            return boundary[(int)position.x][(int)position.y] ? 0 : -1;
            return -1;
        }
        else
        {
			if(position->x > imageWidth || position->x < 0)
				return M_PI_2;
			else
			{
	            if (position->y > imageHeight)
	            	return 0;
	            else
	            	return -1;
			}
        }

//        try {
//            return boundary[(int) position.x][(int) position.y] ? 0 : -1;
//        } catch (ArrayIndexOutOfBoundsException exp) {
//            if (position.y < 0)
//                return -1;
//            else
//            {
//                if(position.x > imageWidth || position.x < 0)
//                    return Math.PI/2.0;
//                return 0;
//            }
//        }
    }

    /**
     * Make a hole in the ground
     *
     * @param position
     *            Of the center of the hole
     */
//    void makeCrater(Vector2D position, int radius) {
//        /**
//         * Change rendering modes
//         */
//        Graphics2D g = this.foregroundB.getBufferedImage().createGraphics();
//        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
//        g.setComposite(AlphaComposite.DstOut);

//        /**
//         * Draw the crater at the correct location
//         */
//        int startx = (int) position.x - radius / 2;
//        int starty = (int) position.y - radius / 2;
//        int width = radius;
//        int height = radius;
//        g.fillOval(startx, starty, width, height);
//        g.dispose();

//        /**
//         * Refresh ground positions
//         */
//        parseGround(startx, starty, width, height);

//    }

    void draw()
    {

    }
//    void draw(ListGraphics g) {

//        g.drawPicture(imageWidth / 2, imageHeight / 2, foregroundB);

//        // draw bound of ground
//        if (Constants.DRAW_BOUNDINGBOXES) {
//            g.setColor(Color.RED);
//            for (int i = 0; i < foregroundB.getWidth(); i++) {
//                for (int j = 0; j < foregroundB.getHeight(); j++) {
//                    if (boundary[i][j]) {
//                        g.drawRect(i, j, 1, 1);
//                    }
//                }
//            }
//        }
//    }

//    /**
//     * @TODO this has nothing to do here
//     */
//    void initialize() {
//        // Reload the background images
//        foregroundB = gameField;
//        parseGround(0, 0, imageWidth, imageHeight);
//    }
};

#endif // GROUND

