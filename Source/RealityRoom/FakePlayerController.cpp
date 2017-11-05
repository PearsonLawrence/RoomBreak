// Fill out your copyright notice in the Description page of Project Settings.

#include "FakePlayerController.h"

#include "GameFramework/GameState.h"

AFakePlayerController::AFakePlayerController()
{
        PrimaryActorTick.bCanEverTick = true;

        PlaybackStartTime = 0.0f;
        IsPlaying = false;
        LastUsedIndex = 0;
}

void AFakePlayerController::Tick(float DeltaTime)
{
        // Recording Logic

        // Playing Logic

        if(!IsPlaying) { return; }

        /*
        auto viewport = GEngine->GameViewport->Viewport;

        if(viewport != nullptr)
        {

        }

        FKey key = FKey("Jump");
        */
        //auto Client = GEngine->GameViewport->Viewport->GetClient();
        //Client->InputKey(GEngine->GameViewport->Viewport, 0, key, EInputEvent::IE_Pressed);

        //bool res = InputAxis(FKey("MoveForward"), 1, DeltaTime, 2, false );
        //bool wow = InputKey(FKey("Jump"), EInputEvent::IE_Pressed, 1.0f, false);
        //bool heck = InputKey(FKey(TEXT("Jump")), EInputEvent::IE_Pressed, 1.0f, false);

        float currentTime  = GetPlaybackTime();
        //UE_LOG(LogTemp, Warning, TEXT("Your message 1"));
        

        FRealityRoomInput * input = nullptr;

        for(int i = 0; i < InputBuffer.Num(); ++i)
        {
                if (InputBuffer[i].Timestamp > currentTime)
                {
                        LastUsedIndex = ((0 > i - 1) ? 0 : i - 1);
                        input = &InputBuffer[LastUsedIndex];
                        break;
                }
        }

        // did we find one that we can use?
        if(input != nullptr)
        {
                FRealityRoomInput& previousInputs = *(input - (0 > LastUsedIndex - 1 ? 0 : LastUsedIndex - 1));
                FRealityRoomInput& relevantInputs = (*input);

                // fuck
                //UE_LOG(LogTemp, Warning, TEXT("Your message"));

                //InputAxis(FKey("MouseX"), relevantInputs.TurnRight - previousInputs.TurnRight, DeltaTime, 2, false);
                //InputAxis(FKey("MouseY"), relevantInputs.LookUp - previousInputs.LookUp, DeltaTime, 2, false);

                if(relevantInputs.Interact)
                {
                        InputKey(FKey("E"), EInputEvent::IE_Pressed, 1.0f, false);
                }
                //InputAxis(FKey("W"), relevantInputs.MoveForward - previousInputs.MoveForward, DeltaTime, 2, false );
                //InputAxis(FKey("D"), relevantInputs.MoveRight - previousInputs.MoveRight, DeltaTime,2,false);
                //InputAxis(FKey(" "), relevantInputs.Jump - previousInputs.Jump, DeltaTime,2,false);
                
                
                APawn * pawn = GetPawn();
                pawn->AddControllerPitchInput(relevantInputs.LookUp);
                pawn->AddControllerYawInput(relevantInputs.TurnRight);

                FVector moveX = pawn->GetActorTransform().TransformVector(FVector(1.0f, 0.0f, 0.0f));
                pawn->AddMovementInput(moveX, relevantInputs.MoveForward, false);

                FVector moveY = pawn->GetActorTransform().TransformVector(FVector(0.0f, 1.0f, 0.0f));
                pawn->AddMovementInput(moveY, relevantInputs.MoveRight, false);
                
        }
}

void AFakePlayerController::StartPlayback()
{
        AGameState* const gamestate = GetWorld() != nullptr ? GetWorld()->GetGameState<AGameState>() : nullptr;

        PlaybackStartTime = gamestate->ElapsedTime;
        IsPlaying = true;
}

void AFakePlayerController::StopPlayback()
{
        IsPlaying = false;
}

float AFakePlayerController::GetPlaybackTime()
{
        AGameState* const gamestate = GetWorld() != nullptr ? GetWorld()->GetGameState<AGameState>() : nullptr;

        if(gamestate == nullptr) { return -1.0f; }

        return gamestate->ElapsedTime - PlaybackStartTime;
}

void AFakePlayerController::StartRecording()
{
        AGameState* const gamestate = GetWorld() != nullptr ? GetWorld()->GetGameState<AGameState>() : nullptr;
        

        IsRecording = true;
        RecordStartTime = gamestate->ElapsedTime;
        RecordStartTransform = GetPawn()->GetActorTransform();
}

void AFakePlayerController::StopRecording()
{
        IsRecording = false;
}