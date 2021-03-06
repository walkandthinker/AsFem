//****************************************************************
//* This file is part of the AsFem framework
//* A Simple Finite Element Method program (AsFem)
//* All rights reserved, Yang Bai @ CopyRight 2021
//* https://github.com/yangbai90/AsFem.git
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Author : Yang Bai
//+++ Date   : 2020.11.30
//+++ Purpose: implement the residual and jacobian for body source
//+++          contribution to our system equation
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ElmtSystem/BulkElmtSystem.h"

void BulkElmtSystem::BodySourceElmt(const FECalcType &calctype,
                const int &nDim,const int &nNodes,const int &nDofs,
                const double &t,const double &dt,const double (&ctan)[2],
                const Vector3d &gpCoords,
                const vector<double> &gpU,const vector<double> &gpV,
                const vector<Vector3d> &gpGradU,const vector<Vector3d> &gpGradV,
                const double &test,const double &trial,
                const Vector3d &grad_test,const Vector3d &grad_trial,
                const ScalarMateType &ScalarMaterials,
                const VectorMateType &VectorMaterials,
                const Rank2MateType &Rank2Materials,
                const Rank4MateType &Rank4Materials,
                vector<double> &gpHist,vector<double> &gpHistOld,vector<double> &gpProj,
                MatrixXd &localK,VectorXd &localR){
    //*******************************************************
    //*** to get rid of the warning for unused variables  ***
    //*** for normal users, you dont need to do this      ***
    //*******************************************************
    if(nDim||nNodes||nDofs||t||dt||ctan[0]||gpCoords(1)||gpU.size()||gpV.size()||
       gpGradU.size()||gpGradV.size()||test||trial||grad_test(1)||grad_trial(1)||
       ScalarMaterials.size()||VectorMaterials.size()||Rank2Materials.size()||Rank4Materials.size()||
       gpHist.size()||gpHistOld.size()||gpProj.size()){}
    
    switch (calctype){
    case FECalcType::ComputeResidual:
        try{
            localR(1)=ScalarMaterials.at("force")*test;
        }
        catch(const std::exception& e){
            MessagePrinter::PrintErrorTxt("the scalar quantity named 'force' cant be found, please check your material definition");
            std::cerr << e.what() << '\n';
            MessagePrinter::AsFem_Exit();
        }
        break;
    case FECalcType::ComputeJacobian:
        localK(1,1)=0.0;
        break;
    case FECalcType::InitHistoryVariable:
        gpHist[0]=0.0;
        break;
    case FECalcType::UpdateHistoryVariable:
        gpHistOld=gpHist;
        break;
    case FECalcType::Projection:
        gpProj[0]=gpU[0];
        gpProj[1]=gpGradU[0](1);
        gpProj[2]=gpGradU[0](2);
        gpProj[3]=gpGradU[0](3);
        break;
    default:
        MessagePrinter::PrintErrorTxt("unsupported FEM calculation type in Laplace element");
        MessagePrinter::AsFem_Exit();
        break;
    }
}