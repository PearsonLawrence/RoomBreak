// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealityRoomInput.h"
#include "GameFramework/PlayerController.h"

#include "FakePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class REALITYROOM_API AFakePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFakePlayerController();

	UPROPERTY(BlueprintReadWrite, Category = Input)
	TArray<FRealityRoomInput> InputBuffer;

	UPROPERTY(BlueprintReadWrite, Category = Input)
	FTransform RecordStartTransform;

	UPROPERTY(BlueprintReadOnly, Category = Input)
	float RecordStartTime;

	UPROPERTY(BlueprintReadOnly, Category = Input)
	float PlaybackStartTime;

	UPROPERTY(BlueprintReadOnly, Category = Input)
	bool IsPlaying;

	UPROPERTY(BlueprintReadOnly, Category = Input)
	bool IsRecording;

	UPROPERTY(BlueprintReadOnly, Category = Input)
	int32 LastUsedIndex;

	UFUNCTION(BlueprintCallable, Category = Input)
	void StartPlayback();

	UFUNCTION(BlueprintCallable, Category = Input)
	void StopPlayback();

	UFUNCTION(BlueprintCallable, Category = Input)
	float GetPlaybackTime();

	UFUNCTION(BlueprintCallable, Category = Input)
	void StartRecording();

	UFUNCTION(BlueprintCallable, Category = Input)
	void StopRecording();

	virtual void Tick(float DeltaTime) override;
};
