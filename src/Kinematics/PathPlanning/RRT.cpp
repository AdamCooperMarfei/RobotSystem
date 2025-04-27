#include"RRT.h"
#include<math.h>
#include<limits>

namespace PathPlanning{
    bool RRT::CollisionCheck(Node* node){
        for(std::vector<double> item:ob_list){
            if(std::sqrt(std::pow((item[0] - node->x_), 2) + std::pow((item[1] - node->y_), 2)) <= item[2]){
                return false;
            }
        }
        return true;
    }

    std::vector<double> RRT::calc_distance_and_angle(Node* from_node, Node* to_node){
        double dx = to_node->x_ - from_node->x_;
        double dy = to_node->y_ - from_node->y_;
        double d = std::sqrt(dx * dx + dy * dy);
        double theta = std::atan2(dy, dx);
        return {d, theta};
    }

    Node* RRT::steer(Node* from_node, Node* to_node, 
        float extend_length = std::numeric_limits<double>::max()){
        Node* new_node = new Node(from_node->x_, from_node->y_);
        std::vector<double> dist_angle = calc_distance_and_angle(from_node, to_node);
        new_node->path_x.push_back(new_node->x_);
        new_node->path_y.push_back(new_node->y_);
        if(extend_length > dist_angle[0])
            extend_length = dist_angle[0];
        int n_expand = std::floor(extend_length / path_resolution);
        for(int i = 0; i < n_expand; ++i){
            new_node->x_ += path_resolution * std::cos(dist_angle[1]);
            new_node->y_ += path_resolution * std::sin(dist_angle[1]);
            new_node->path_x.push_back(new_node->x_);
            new_node->path_y.push_back(new_node->y_);

        }
        std::vector<double> dist_angle_new = calc_distance_and_angle(new_node, to_node);
        
        


    }
}