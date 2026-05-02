// WomenCharacter.cpp
#include "WomenCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"

namespace
{
    static void ConfigureModularMeshComponent(USkeletalMeshComponent* MeshComponent, USkeletalMeshComponent* ParentMesh)
    {
        if (!MeshComponent || !ParentMesh)
        {
            return;
        }

        MeshComponent->SetupAttachment(ParentMesh);
        MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        MeshComponent->SetGenerateOverlapEvents(false);
        MeshComponent->SetCastShadow(true);
        MeshComponent->bCastDynamicShadow = true;
        MeshComponent->bCastHiddenShadow = true;
    }
}

AWomenCharacter::AWomenCharacter()
{
    bReplicates = true;
    SetReplicateMovement(true);

    // Third-person full body: other players can see it,
    // but it still casts the owner's full-body shadow.
    GetMesh()->SetOwnerNoSee(true);
    GetMesh()->SetCastShadow(true);
    GetMesh()->bCastHiddenShadow = true;


    PrimaryActorTick.bCanEverTick = true;

    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());


    FirstPersonCameraComponent->SetRelativeLocation(FVector(0.f, 0.f, 64.f));

    FirstPersonCameraComponent->bUsePawnControlRotation = true;

    // First-person mesh: only the owning player sees it. It should not cast world shadows.
    // Usually this mesh contains first-person arms and visible lower body/legs, but no head.
    FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
    FirstPersonMesh->SetupAttachment(FirstPersonCameraComponent);
    FirstPersonMesh->SetOnlyOwnerSee(true);
    FirstPersonMesh->SetOwnerNoSee(false);
    FirstPersonMesh->SetCastShadow(false);
    FirstPersonMesh->bCastDynamicShadow = false;
    FirstPersonMesh->bCastHiddenShadow = false;
    FirstPersonMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    FirstPersonMesh->SetGenerateOverlapEvents(false);

    HeadMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeadMesh"));
    ConfigureModularMeshComponent(HeadMesh, GetMesh());

    HairMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HairMesh"));
    ConfigureModularMeshComponent(HairMesh, GetMesh());

    TopMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Topmesh"));
    ConfigureModularMeshComponent(TopMesh, GetMesh());

    HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandMesh"));
    ConfigureModularMeshComponent(HandMesh, GetMesh());

    PantsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PantsMesh"));
    ConfigureModularMeshComponent(PantsMesh, GetMesh());

    ShoesMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShoesMesh"));
    ConfigureModularMeshComponent(ShoesMesh, GetMesh());

    HoldPoint = CreateDefaultSubobject<USceneComponent>(TEXT("HoldPoint"));
    HoldPoint->SetupAttachment(FirstPersonCameraComponent);

    HoldPoint->SetRelativeLocation(FVector(80.f, 20.f, -15.f));
}

void AWomenCharacter::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    RefreshModularMeshes();
}


void AWomenCharacter::TeleportToLocation(FVector NewLocation, FRotator NewRotation)
{
    SetActorLocation(NewLocation);
    SetActorRotation(NewRotation);

}

void AWomenCharacter::TeleportToTarget(AActor* TargetActor)
{
    if (TargetActor)
    {
        FVector TargetLocation = TargetActor->GetActorLocation();
        FRotator TargetRotation = TargetActor->GetActorRotation();
        TeleportTo(TargetLocation, TargetRotation);
    }
}

void AWomenCharacter::BeginPlay()
{
    Super::BeginPlay();

    RefreshModularMeshes();
}

void AWomenCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!FirstPersonCameraComponent)
    {
        return;
    }

    FVector CameraRelativeLocation = FirstPersonCameraComponent->GetRelativeLocation();
    const float TargetCameraHeight = IsSquat ? CrouchingCameraHeight : StandingCameraHeight;

    if (CameraCrouchInterpSpeed <= 0.f)
    {
        CameraRelativeLocation.Z = TargetCameraHeight;
    }
    else
    {
        CameraRelativeLocation.Z = FMath::FInterpTo(
            CameraRelativeLocation.Z,
            TargetCameraHeight,
            DeltaTime,
            CameraCrouchInterpSpeed
        );
    }

    FirstPersonCameraComponent->SetRelativeLocation(CameraRelativeLocation);
}

void AWomenCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AWomenCharacter, IsSquat);
    DOREPLIFETIME(AWomenCharacter, IsSprint);
    DOREPLIFETIME(AWomenCharacter, IsSquatThrowing);
    DOREPLIFETIME(AWomenCharacter, IsStandThrowing);
    DOREPLIFETIME(AWomenCharacter, IsMiddleHandleTime);
}

void AWomenCharacter::RefreshModularMeshes()
{
    USkeletalMeshComponent* BaseMesh = GetMesh();
    if (!BaseMesh)
    {
        return;
    }

    TArray<USkeletalMeshComponent*> ModularMeshes =
    {
        HeadMesh,
        HairMesh,
        TopMesh,
        PantsMesh,
        ShoesMesh,
        HandMesh
    };

    for (USkeletalMeshComponent* ModularMesh : ModularMeshes)
    {
        if (!ModularMesh)
        {
            continue;
        }

        ModularMesh->SetLeaderPoseComponent(BaseMesh);
        ModularMesh->SetRelativeLocation(FVector::ZeroVector);
        ModularMesh->SetRelativeRotation(FRotator::ZeroRotator);
        ModularMesh->SetRelativeScale3D(FVector::OneVector);
    }
}

void AWomenCharacter::RebuildModularMeshes()
{
    RefreshModularMeshes();
}
