/*
===========================================================================
This code is part of the "Source Code" content in
Purpleprint 2 - Kit by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/PurpleprintKit>

The MIT License (MIT)
Copyright (c) 2014-2016 David Palacios (Hevedy) <https://github.com/Hevedy>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================
*/

/*
================================================
PPKLibraryTools.h
================================================
*/


#pragma once

#include "PPKLibraryMath.h"

#include <chrono>
#include <random>
#include <math.h>


#include "PPKLibraryTools.generated.h"

UENUM()
enum class EIniFilesList : uint8 {
	GGameIni 				UMETA( DisplayName = "Game" ),
	GGameUserSettingsIni	UMETA( DisplayName = "User Settings" ),
	GScalabilityIni			UMETA( DisplayName = "Scalability" ),
	GInputIni				UMETA( DisplayName = "Input" ),
	GEngineIni				UMETA( DisplayName = "Engine" )
};

UCLASS()
class PPKLIBRARY_API UPPKLibraryTools : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UPPKLibraryTools( const FObjectInitializer& ObjectInitializer );
private:

protected:

public:

	/** Returns a float from two ints A and B to A.B */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Make Float" ), Category = "PP2KLibrary|Math|Float" )
		static float MakeFloatFromInts( const int32 A, const int32 B );

	/** Returns split a float into two ints A.B to A and B */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Break Float" ), Category = "PP2KLibrary|Math|Float" )
		static int32 DivideFloatIntoInts( const float Ref, int32& B );

	/** Returns the float inverted A.B to B.A */
	UFUNCTION( BlueprintCallable, meta = ( DisplayName = "Invert Float Order" ), Category = "PP2KLibrary|Math|Float" )
		static float InvertFloat( const float floatValue );

	/** Returns FVector2D(A,B) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector2D FloatSplitToVector2D( const float FloatValue );

	/** Returns FVector(A,B,0) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector FloatSplitToVector( const float FloatValue );

	/** Returns FVector4(A,B,0,0) from a float A.B */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 FloatSplitToVector4( const float FloatValue );

	/** Returns FVector2D(A,B) from the FVector(A,B,C) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector2D VectorToVector2D( const FVector &VectorValue );

	/** Returns FVector2D(A,B) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector2D Vector4ToVector2D( const FVector4 &Vector4Value );

	/** Returns FVector(A,B,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector Vector2DToVector( const FVector2D &Vector2DValue );

	/** Returns FVector(A,B,C) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector Vector4ToVector( const FVector4 &Vector4Value );

	/** Returns FVector4(A,B,0,0) from the FVector2D(A,B) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 Vector2DToVector4( const FVector2D &Vector2DValue );

	/** Returns FVector4(A,B,C,0) from the FVector(A,B,C) */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 VectorToVector4( const FVector &VectorValue );

	/** Returns FRotator(C,B,A) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Rotator" )
		static FRotator RotatorOrderInvert( const FRotator &rotatorValue );

	/** Returns FVector2D(B,A) from the FVector2D(A,B) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector2D" )
		static FVector2D Vector2DOrderInvert( const FVector2D &vector2DValue );

	/** Returns FVector(C,B,A) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector VectorOrderInvert( const FVector &vectorValue );

	/** Returns FVector4(D,C,B,A) from the FVector4(A,B,C,D) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector4" )
		static FVector4 Vector4OrderInvert( const FVector4 &vector4Value );

	/** Returns FRotator(C,A,B) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Rotator" )
		static FRotator RotatorOrderRight( const FRotator &rotatorValue );

	/** Returns FVector(C,A,B) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector VectorOrderRight( const FVector &vectorValue );

	/** Returns FVector(D,A,B,C) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 Vector4OrderRight( const FVector4 &vector4Value );

	/** Returns FRotator(B,C,A) from the FRotator(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Rotator" )
		static FRotator RotatorOrderLeft( const FRotator &rotatorValue );

	/** Returns FVector(B,C,A) from the FVector(A,B,C) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector VectorOrderLeft( const FVector &vectorValue );

	/** Returns FVector(B,C,D,A) from the FVector(A,B,C,D) */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Math|Vector" )
		static FVector4 Vector4OrderLeft( const FVector4 &vector4Value );

	/** Returns the value of the selected bool from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static bool GetConfigBool( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected int32 from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static int32 GetConfigInt( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected float from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static float GetConfigFloat( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FVector from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FVector GetConfigVector( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FRotator from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FRotator GetConfigRotator( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FLinearColor from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FLinearColor GetConfigColor( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FString from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FString GetConfigString( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Returns the value of the selected FVector2D from the selected ini config file */
	UFUNCTION( BlueprintPure, Category = "PP2KLibrary|Config" )
		static FVector2D GetConfigVector2D( const FString sectionName, const FString variableName, const EIniFilesList iniFile );

	/** Set the value of the selected bool from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigBool( const FString sectionName, const FString variableName, const bool value, const EIniFilesList iniFile );

	/** Set the value of the selected int32 from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigInt( const FString sectionName, const FString variableName, const int32 value, const EIniFilesList iniFile );

	/** Set the value of the selected float from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigFloat( const FString sectionName, const FString variableName, const float value, const EIniFilesList iniFile );

	/** Set the value of the selected FVector from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigVector( const FString sectionName, const FString variableName, const FVector value, const EIniFilesList iniFile );

	/** Set the value of the selected FRotator from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigRotator( const FString sectionName, const FString variableName, const FRotator value, const EIniFilesList iniFile );

	/** Set the value of the selected FLinearColor from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigColor( const FString sectionName, const FString variableName, const FLinearColor value, const EIniFilesList iniFile );

	/** Set the value of the selected FString from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigString( const FString sectionName, const FString variableName, const FString value, const EIniFilesList iniFile );

	/** Set the value of the selected FVector2D from the selected ini config file */
	UFUNCTION( BlueprintCallable, Category = "PP2KLibrary|Config" )
		static void SetConfigVector2D( const FString sectionName, const FString variableName, const FVector2D value, const EIniFilesList iniFile );

};