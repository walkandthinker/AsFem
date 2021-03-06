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
//+++ Date   : 2020.11.29
//+++ Purpose: we list all of our elements here for different models
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ElmtSystem/BulkElmtSystem.h"

void BulkElmtSystem::RunBulkElmtLibs(const FECalcType &calctype,const ElmtType &elmtytype,
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
    switch (elmtytype)
    {
    case ElmtType::LAPLACEELMT:
        LaplaceElmt(calctype,nDim,nNodes,nDofs,t,dt,ctan,
                    gpCoords,gpU,gpV,gpGradU,gpGradV,
                    test,trial,grad_test,grad_trial,
                    ScalarMaterials,VectorMaterials,Rank2Materials,Rank4Materials,
                    gpHist,gpHistOld,gpProj,
                    localK,localR);
        break;
    case ElmtType::POISSONELMT:
        PoissonElmt(calctype,nDim,nNodes,nDofs,t,dt,ctan,
                    gpCoords,gpU,gpV,gpGradU,gpGradV,
                    test,trial,grad_test,grad_trial,
                    ScalarMaterials,VectorMaterials,Rank2Materials,Rank4Materials,
                    gpHist,gpHistOld,gpProj,
                    localK,localR);
        break;
    case ElmtType::TIMEDERIVELMT:
        TimeDerivElmt(calctype,nDim,nNodes,nDofs,t,dt,ctan,
                      gpCoords,gpU,gpV,gpGradU,gpGradV,
                      test,trial,grad_test,grad_trial,
                      ScalarMaterials,VectorMaterials,Rank2Materials,Rank4Materials,
                      gpHist,gpHistOld,gpProj,
                      localK,localR);
        break;
    case ElmtType::DIFFUSIONELMT:
        DiffusionElmt(calctype,nDim,nNodes,nDofs,t,dt,ctan,
                      gpCoords,gpU,gpV,gpGradU,gpGradV,
                      test,trial,grad_test,grad_trial,
                      ScalarMaterials,VectorMaterials,Rank2Materials,Rank4Materials,
                      gpHist,gpHistOld,gpProj,
                      localK,localR);
        break;
    case ElmtType::CAHNHILLIARDELMT:
        CahnHilliardElmt(calctype,nDim,nNodes,nDofs,t,dt,ctan,
                      gpCoords,gpU,gpV,gpGradU,gpGradV,
                      test,trial,grad_test,grad_trial,
                      ScalarMaterials,VectorMaterials,Rank2Materials,Rank4Materials,
                      gpHist,gpHistOld,gpProj,
                      localK,localR);
        break;
    case ElmtType::MECHANICSELMT:
        MechanicsElmt(calctype,nDim,nNodes,nDofs,t,dt,ctan,
                      gpCoords,gpU,gpV,gpGradU,gpGradV,
                      test,trial,grad_test,grad_trial,
                      ScalarMaterials,VectorMaterials,Rank2Materials,Rank4Materials,
                      gpHist,gpHistOld,gpProj,
                      localK,localR);
        break;
    default:
        MessagePrinter::PrintErrorTxt("unsupported element type in ElmtSystem, please check your code or your input file");
        MessagePrinter::AsFem_Exit();
        break;
    }
}