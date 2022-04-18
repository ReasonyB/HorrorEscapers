// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(HEscapers, Log, All);
#define HELOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") +  FString::FromInt(__LINE__) + TEXT(")"))
#define HELOG_S(Verbosity) UE_LOG(HEscapers, Verbosity, TEXT("%s"),*HELOG_CALLINFO)
#define HELOG(Verbosity, Format, ...) UE_LOG(HEscapers, Verbosity, TEXT("%s %s"), *HELOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))