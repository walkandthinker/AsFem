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
//+++ Date   : 2020.06.26
//+++ Purpose: implement msh(ver=4) mesh file importer
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "Mesh/MeshIOBase.h"
#include "Mesh/MeshType.h"

class Gmsh4IO:public MeshIOBase{
public:
    Gmsh4IO(){
        _MeshFileName.clear();
        _HasSetMeshFileName=false;
    }

    virtual bool ReadMeshFromFile(Mesh &mesh) override;
    virtual void SetMeshFileName(string filename)override{_MeshFileName=filename;_HasSetMeshFileName=true;}
    virtual string GetMeshFileName()const override{return _MeshFileName;}

private:
    int GetElmtNodesNumFromGmshElmtType(const int &elmttype) const;
    int GetElmtDimFromGmshElmtType(const int &elmttype) const;
    int GetElmtOrderFromGmshElmtType(const int &elmttype)const;
    MeshType GetElmtMeshTypeFromGmshElmtType(const int &elmttype)const;
    string GetElmtTypeNameFromGmshElmtType(const int &elmttype)const;

    int GetSubElmtNodesNumFromGmshElmtType(const int &elmttype) const;
    int GetSubElmtDimFromGmshElmtType(const int &elmttype) const;
    int GetSubElmtOrderFromGmshElmtType(const int &elmttype)const;
    MeshType GetSubElmtMeshTypeFromGmshElmtType(const int &elmttype)const;

};