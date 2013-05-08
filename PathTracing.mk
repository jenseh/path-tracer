##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PathTracing
ConfigurationName      :=Debug
WorkspacePath          := "/home/jens/.codelite/default"
ProjectPath            := "/home/jens/.codelite/default/PathTracing"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jens
Date                   :=05/09/2013
CodeLitePath           :="/home/jens/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="PathTracing.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/OpenEXR 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)IlmImf $(LibrarySwitch)Half $(LibrarySwitch)assimp $(LibrarySwitch)rt $(LibrarySwitch)gomp 
ArLibs                 :=  "IlmImf" "Half" "assimp" "rt" "gomp" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS := -std=c++11 -O3 -fopenmp -g $(Preprocessors)
CFLAGS   := -std=c++11 -O3 -fopenmp -g $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/AABB$(ObjectSuffix) $(IntermediateDirectory)/Camera$(ObjectSuffix) $(IntermediateDirectory)/Image$(ObjectSuffix) $(IntermediateDirectory)/Intersection$(ObjectSuffix) $(IntermediateDirectory)/Model$(ObjectSuffix) $(IntermediateDirectory)/PathTracer$(ObjectSuffix) $(IntermediateDirectory)/Ray$(ObjectSuffix) $(IntermediateDirectory)/Scene$(ObjectSuffix) $(IntermediateDirectory)/Sphere$(ObjectSuffix) \
	$(IntermediateDirectory)/Square$(ObjectSuffix) $(IntermediateDirectory)/Triangle$(ObjectSuffix) $(IntermediateDirectory)/Material$(ObjectSuffix) $(IntermediateDirectory)/Intersectable$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/AABB$(ObjectSuffix): AABB.cpp $(IntermediateDirectory)/AABB$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/AABB.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AABB$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AABB$(DependSuffix): AABB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AABB$(ObjectSuffix) -MF$(IntermediateDirectory)/AABB$(DependSuffix) -MM "AABB.cpp"

$(IntermediateDirectory)/AABB$(PreprocessSuffix): AABB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AABB$(PreprocessSuffix) "AABB.cpp"

$(IntermediateDirectory)/Camera$(ObjectSuffix): Camera.cpp $(IntermediateDirectory)/Camera$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Camera$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Camera$(DependSuffix): Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Camera$(ObjectSuffix) -MF$(IntermediateDirectory)/Camera$(DependSuffix) -MM "Camera.cpp"

$(IntermediateDirectory)/Camera$(PreprocessSuffix): Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Camera$(PreprocessSuffix) "Camera.cpp"

$(IntermediateDirectory)/Image$(ObjectSuffix): Image.cpp $(IntermediateDirectory)/Image$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Image$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Image$(DependSuffix): Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Image$(ObjectSuffix) -MF$(IntermediateDirectory)/Image$(DependSuffix) -MM "Image.cpp"

$(IntermediateDirectory)/Image$(PreprocessSuffix): Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Image$(PreprocessSuffix) "Image.cpp"

$(IntermediateDirectory)/Intersection$(ObjectSuffix): Intersection.cpp $(IntermediateDirectory)/Intersection$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Intersection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Intersection$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Intersection$(DependSuffix): Intersection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Intersection$(ObjectSuffix) -MF$(IntermediateDirectory)/Intersection$(DependSuffix) -MM "Intersection.cpp"

$(IntermediateDirectory)/Intersection$(PreprocessSuffix): Intersection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Intersection$(PreprocessSuffix) "Intersection.cpp"

$(IntermediateDirectory)/Model$(ObjectSuffix): Model.cpp $(IntermediateDirectory)/Model$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Model$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Model$(DependSuffix): Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Model$(ObjectSuffix) -MF$(IntermediateDirectory)/Model$(DependSuffix) -MM "Model.cpp"

$(IntermediateDirectory)/Model$(PreprocessSuffix): Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Model$(PreprocessSuffix) "Model.cpp"

$(IntermediateDirectory)/PathTracer$(ObjectSuffix): PathTracer.cpp $(IntermediateDirectory)/PathTracer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/PathTracer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PathTracer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PathTracer$(DependSuffix): PathTracer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PathTracer$(ObjectSuffix) -MF$(IntermediateDirectory)/PathTracer$(DependSuffix) -MM "PathTracer.cpp"

$(IntermediateDirectory)/PathTracer$(PreprocessSuffix): PathTracer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PathTracer$(PreprocessSuffix) "PathTracer.cpp"

$(IntermediateDirectory)/Ray$(ObjectSuffix): Ray.cpp $(IntermediateDirectory)/Ray$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Ray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ray$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ray$(DependSuffix): Ray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ray$(ObjectSuffix) -MF$(IntermediateDirectory)/Ray$(DependSuffix) -MM "Ray.cpp"

$(IntermediateDirectory)/Ray$(PreprocessSuffix): Ray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ray$(PreprocessSuffix) "Ray.cpp"

$(IntermediateDirectory)/Scene$(ObjectSuffix): Scene.cpp $(IntermediateDirectory)/Scene$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Scene$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Scene$(DependSuffix): Scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Scene$(ObjectSuffix) -MF$(IntermediateDirectory)/Scene$(DependSuffix) -MM "Scene.cpp"

$(IntermediateDirectory)/Scene$(PreprocessSuffix): Scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Scene$(PreprocessSuffix) "Scene.cpp"

$(IntermediateDirectory)/Sphere$(ObjectSuffix): Sphere.cpp $(IntermediateDirectory)/Sphere$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Sphere.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sphere$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sphere$(DependSuffix): Sphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sphere$(ObjectSuffix) -MF$(IntermediateDirectory)/Sphere$(DependSuffix) -MM "Sphere.cpp"

$(IntermediateDirectory)/Sphere$(PreprocessSuffix): Sphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sphere$(PreprocessSuffix) "Sphere.cpp"

$(IntermediateDirectory)/Square$(ObjectSuffix): Square.cpp $(IntermediateDirectory)/Square$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Square.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Square$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Square$(DependSuffix): Square.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Square$(ObjectSuffix) -MF$(IntermediateDirectory)/Square$(DependSuffix) -MM "Square.cpp"

$(IntermediateDirectory)/Square$(PreprocessSuffix): Square.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Square$(PreprocessSuffix) "Square.cpp"

$(IntermediateDirectory)/Triangle$(ObjectSuffix): Triangle.cpp $(IntermediateDirectory)/Triangle$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Triangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Triangle$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Triangle$(DependSuffix): Triangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Triangle$(ObjectSuffix) -MF$(IntermediateDirectory)/Triangle$(DependSuffix) -MM "Triangle.cpp"

$(IntermediateDirectory)/Triangle$(PreprocessSuffix): Triangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Triangle$(PreprocessSuffix) "Triangle.cpp"

$(IntermediateDirectory)/Material$(ObjectSuffix): Material.cpp $(IntermediateDirectory)/Material$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Material.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Material$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Material$(DependSuffix): Material.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Material$(ObjectSuffix) -MF$(IntermediateDirectory)/Material$(DependSuffix) -MM "Material.cpp"

$(IntermediateDirectory)/Material$(PreprocessSuffix): Material.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Material$(PreprocessSuffix) "Material.cpp"

$(IntermediateDirectory)/Intersectable$(ObjectSuffix): Intersectable.cpp $(IntermediateDirectory)/Intersectable$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jens/.codelite/default/PathTracing/Intersectable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Intersectable$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Intersectable$(DependSuffix): Intersectable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Intersectable$(ObjectSuffix) -MF$(IntermediateDirectory)/Intersectable$(DependSuffix) -MM "Intersectable.cpp"

$(IntermediateDirectory)/Intersectable$(PreprocessSuffix): Intersectable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Intersectable$(PreprocessSuffix) "Intersectable.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/AABB$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AABB$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AABB$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Camera$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Camera$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Camera$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Image$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Image$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Image$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Intersection$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Intersection$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Intersection$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Model$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Model$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Model$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PathTracer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PathTracer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PathTracer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Ray$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Ray$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Ray$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Scene$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Scene$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Scene$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Sphere$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Sphere$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Sphere$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Square$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Square$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Square$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Triangle$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Triangle$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Triangle$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Material$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Material$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Material$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Intersectable$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Intersectable$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Intersectable$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/PathTracing"


