#ifndef CLOTH_CALC_H
#define CLOTH_CALC_H

#include <DivergingColorMaps.hpp>
#include <nanoflann.hpp>

#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <map>

#include <TriMesh/TriMesh.h>
// #include <libmesh/node_elem.h>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>

#include <ply_Module.h>


class cloth_calc
{

public:
    cloth_calc(std::string Cloth_Template, std::string Cloth_Reference, std::string Cloth_Base );
    ~cloth_calc();

    void cloth_init_vert();
    void cloth_init_neighbor();
    void cloth_map_neighbor(int MODE);
    void cloth_map_adjacent();
    void cloth_map_neighbor_kdTree(double Per);

    void cloth_vec();
    void cloth_eig_2D();
    void cloth_eig_3D();
    void cloth_eig_assemble(Eigen::MatrixXd U);
    void cloth_stretchTensor_2D();
    void cloth_stretchTensor_3D(Eigen::MatrixXd Eigenval, Eigen::MatrixXd Eigenvec);
    void cloth_stretchTensor_neighbor();
    void cloth_stretchTensor_assemble(Eigen::MatrixXd U, std::map<int, std::vector<int>> MapNeighbor);
    void cloth_stretchTensor_CCM(Eigen::MatrixXd U, Eigen::MatrixXd Eigenval, std::map<int, std::vector<int>> MapNeighbor);
    void cloth_stretchTensor_kdTree(Eigen::MatrixXd U, double Per);
    void cloth_displGrad_2D();

    // USING NEIGHBOR
    void cloth_eig_neighbor(std::map<int, std::vector<int>> MapNeighbor);
    void cloth_eig_neighbor2x(std::map<int, std::vector<int>> MapNeighbor);
    void cloth_eig_neighbor3x(std::map<int, std::vector<int>> MapNeighbor);
    void cloth_eig_neighbor4x(std::map<int, std::vector<int>> MapNeighbor);

    // USING KD-TREE
    void cloth_eig_kdTree(double Per);

    // Wrinkel vector field v
    void cloth_wrink_vec_field(Eigen::MatrixXd Eigenval, Eigen::MatrixXd Eigenvec);

    // Stretching Tensor
    void cloth_velGrad_3D(Eigen::MatrixXd F_CT, Eigen::MatrixXd F_CR, double deltaT);
    void cloth_velGrad_assemble(Eigen::MatrixXd VelGrad, double Per);
    void cloth_velGrad_normalize(Eigen::MatrixXd VelGrad);

    // Optimation Process
    void cloth_rotationTensor(Eigen::MatrixXd F, Eigen::MatrixXd U);
    void cloth_translationVec(Eigen::MatrixXd R, std::map<int, std::vector<int>> MapNeighbor);
    void cloth_transformationMat(Eigen::MatrixXd R, Eigen::MatrixXd t);
    void cloth_update(Eigen::MatrixXd R, Eigen::MatrixXd t);
    void cloth_WriteVerts(Eigen::MatrixXd verts, const std::string &  ifileName);

    void cloth_ReadTransformationMat(std::string Transformation, std::string Frequency);
    void cloth_Opt(Eigen::MatrixXd T, Eigen::MatrixXd F);

    // COLLORMAP
    void cloth_vec_normalize(Eigen::MatrixXd Eigenval, int dim);
    void cloth_WriteColor(Eigen::MatrixXd color, const std::string &  ifileName);



    void test(Eigen::MatrixXd U, std::map<int, std::vector<int>> mapNeighbor);

    std::map<int, std::vector<int>> GetMapNeighbor();
    std::map<int, std::vector<int>> GetMapNeighbor2x();
    std::map<int, std::vector<int>> GetMapNeighbor3x();
    std::map<int, std::vector<int>> GetMapNeighbor4x();
    std::map<int, std::vector<size_t>> GetMapNeighborKdTree();
    std::map<int, std::vector<int>> GetMapAdjacent();

    Eigen::MatrixXd GetEigval();
    Eigen::MatrixXd GetEigvec();
    Eigen::MatrixXd GetStretchTensor_2D();
    Eigen::MatrixXd GetStretchTensor_3D();
    Eigen::MatrixXd GetStretchTensorAsemmble();
    Eigen::MatrixXd GetStretchTensorMap();
    Eigen::MatrixXd GetStretchTensorFreq();
    Eigen::MatrixXd GetDefoGrad();
    Eigen::MatrixXd GetEigval_3D();
    Eigen::MatrixXd GetEigvec_3D();
    Eigen::MatrixXd GetEigval_assemble();
    Eigen::MatrixXd GetEigvec_assemble();
    Eigen::MatrixXd GetEigval_neighbor();
    Eigen::MatrixXd GetEigvec_neighbor();
    Eigen::MatrixXd GetEigval_neighbor2x();
    Eigen::MatrixXd GetEigvec_neighbor2x();
    Eigen::MatrixXd GetEigval_neighbor3x();
    Eigen::MatrixXd GetEigvec_neighbor3x();
    Eigen::MatrixXd GetEigval_neighbor4x();
    Eigen::MatrixXd GetEigvec_neighbor4x();
    Eigen::MatrixXd GetEigval_neighborKdTree();
    Eigen::MatrixXd GetEigvec_neighborKdTree();
    Eigen::MatrixXd GetEigval_norm_dir1();
    Eigen::MatrixXd GetEigval_norm_dir2();
    Eigen::MatrixXd GetEigval_norm_dir3();
    Eigen::MatrixXd GetWrinkVecField();
    Eigen::MatrixXd GetWrinkVecField_norm();
    Eigen::MatrixXd GetRotationTensor();
    Eigen::MatrixXd GetRotationTensorOpt();
    Eigen::MatrixXd GetTranslationVec();
    Eigen::MatrixXd GetTransformationMat();
    Eigen::MatrixXd GetVertsUpdate();
    Eigen::MatrixXd GetStrTensor();
    Eigen::MatrixXd GetRotTensor();
    Eigen::MatrixXd GetStrTensorAsemmble();
    Eigen::MatrixXd GetStrTensor_norm_dir1();


private:
    std::string CT;
    std::string CR;
    std::string BS;
    ply_module* _plyModuleT;
    ply_module* _plyModuleR;
    ply_module* _plyModule;
    ply_module* plyUpdate;

    std::map<int, std::vector<int>> mapNeighbor;
    std::map<int, std::vector<int>> mapNeighbor2x;
    std::map<int, std::vector<int>> mapNeighbor3x;
    std::map<int, std::vector<int>> mapNeighbor4x;
    std::map<int, std::vector<int>> mapAdjacent;
    std::map<int, std::vector<size_t>> mapNeighborKdTree;

    trimesh::TriMesh *_plyMeshT;
    trimesh::TriMesh *_plyMeshR;
    trimesh::TriMesh *_plyMesh;


    Eigen::MatrixXi faces;
    Eigen::MatrixXd vertsT, vertsR, verts;
    Eigen::MatrixXd vertsT_cog;
    Eigen::MatrixXd vertsR_cog;
    Eigen::MatrixXd vertsUpdate;

    // Rohmer et al.
    Eigen::MatrixXd VecT, VecR;
    Eigen::MatrixXd F;
    Eigen::MatrixXd Eigval_2D, Eigvec_2D;
    Eigen::MatrixXd Eigval_3D, Eigvec_3D;
    Eigen::MatrixXd Eigval_assemble, Eigvec_assemble;
    Eigen::MatrixXd U_2D;
    Eigen::MatrixXd H_2D;
    Eigen::MatrixXd U_3D;
    Eigen::MatrixXd U_3D_assem;
    Eigen::MatrixXd U_map;
    Eigen::MatrixXd Freq;

    Eigen::MatrixXd F_der;
    Eigen::MatrixXd F_inv;
    Eigen::MatrixXd L;
    Eigen::MatrixXd D;
    Eigen::MatrixXd W;
    Eigen::MatrixXd D_assem;
    Eigen::MatrixXd D_norm_dir1;
    Eigen::MatrixXd D_norm_dir2;
    Eigen::MatrixXd D_norm_dir3;

    //
    Eigen::MatrixXd Eigval_neighbor, Eigvec_neighbor;
    Eigen::MatrixXd Eigval_neighbor2x, Eigvec_neighbor2x;
    Eigen::MatrixXd Eigval_neighbor3x, Eigvec_neighbor3x;
    Eigen::MatrixXd Eigval_neighbor4x, Eigvec_neighbor4x;
    Eigen::MatrixXd Eigval_neighborKdTree, Eigvec_neighborKdTree;
    Eigen::MatrixXd U_neighbor;
    Eigen::MatrixXd H_neighbor;

    //
    Eigen::MatrixXd v;
    Eigen::MatrixXd v_norm;

    //
    Eigen::MatrixXd R;
    Eigen::MatrixXd t;
    Eigen::MatrixXd T;
    Eigen::MatrixXd R_opt;

    //
    Eigen::MatrixXd Eigval_norm_dir1, Eigval_norm_dir2, Eigval_norm_dir3;
};

#endif // CLOTH_CALC_H
