// QuickHull implementation in Java
// Coded as a package, can be used directly in a program
// @author ketanhwr

package info.ketanhwr.convexhull;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class QuickHull {

    public List<Point> findConvexHull(List<Point> array) {
        List<Point> convexHull = new ArrayList<>();

        Point rightmostPoint = array.get(0);
        Point leftmostPoint = array.get(0);
        for (Point point : array) {
            if (point.getX() < rightmostPoint.getX()) {
                rightmostPoint = point;
            } else if (point.getX() > leftmostPoint.getX()) {
                leftmostPoint = point;
            }
        }
        
        List<Point> leftOfLine = new LinkedList<>();
        List<Point> rightOfLine = new LinkedList<>();
        for (Point point : array) {
            if (point.equals(rightmostPoint) || point.equals(leftmostPoint)) {
                continue;
            }
            if (point.isLeftOfLine(leftmostPoint, rightmostPoint)) {
                leftOfLine.add(point);
            } else {
                rightOfLine.add(point);
            }
        }
        
        convexHull.add(leftmostPoint);
        List<Point> hull = divide(leftOfLine, leftmostPoint, rightmostPoint);
        convexHull.addAll(hull);
        convexHull.add(rightmostPoint);
        
        hull = divide(rightOfLine, rightmostPoint, leftmostPoint);
        convexHull.addAll(hull);
        
        
        return convexHull;
    }

    private List<Point> divide(List<Point> array, Point x1, Point x2) {
        
        List<Point> hull = new ArrayList<>();
        
        if (array.isEmpty()) {
            return hull;
        } else if (array.size() == 1) {
            hull.add(array.get(0));
            return hull;
        }
        
        Point maxDistancePoint = array.get(0);
        List<Point> l1 = new LinkedList<>();
        List<Point> l2 = new LinkedList<>();
        double distance = 0.0;
        for (Point point : array) {
            if (point.getDistanceToLine(x1, x2) > distance) {
                distance = point.getDistanceToLine(x1, x2);
                maxDistancePoint = point;
            }
        }
        
        array.remove(maxDistancePoint);
        
        for (Point point : array) {
            if (point.isLeftOfLine(x1, maxDistancePoint)) {
                l1.add(point);
            } else if (point.isLeftOfLine(maxDistancePoint, x2)) {
                l2.add(point);
            }
        }
        
        array.clear();
        
        List <Point> hullPart = divide(l1, x1, maxDistancePoint);
        hull.addAll(hullPart);
        hull.add(maxDistancePoint);
        hullPart = divide(l2, maxDistancePoint, x2);
        hull.addAll(hullPart);
        
        return hull;
    }
}