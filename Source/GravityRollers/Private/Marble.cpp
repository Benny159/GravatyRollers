#include "Marble.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

AMarble::AMarble()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MarbleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MarbleMesh"));
	RootComponent = MarbleMesh;
	
	InnerCore = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InnerCore"));
	InnerCore->SetupAttachment(MarbleMesh);
	InnerCore->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	TrailEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailEffect"));
	TrailEffect->SetupAttachment(MarbleMesh);
	
	MarbleMesh->SetSimulatePhysics(true);
}

void AMarble::BeginPlay()
{
	Super::BeginPlay();
	UpdatePhysicsProperties();
}

void AMarble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMarble::UpdatePhysicsProperties()
{
	MarbleMesh->SetWorldScale3D(FVector(Size));

	Mass = Weight * MaterialDensity;
	MarbleMesh->SetMassOverrideInKg(NAME_None, Mass);

	MarbleMesh->BodyInstance.LinearDamping = SurfaceRoughness;
	MarbleMesh->BodyInstance.COMNudge = MassDistribution;

	MarbleMesh->SetPhysMaterialOverride(CreatePhysicsMaterial());

	MarbleMesh->BodyInstance.AngularDamping = AngularDamping;

}

UPhysicalMaterial* AMarble::CreatePhysicsMaterial()
{
	UPhysicalMaterial* PhysMat = NewObject<UPhysicalMaterial>(this);

	PhysMat->Restitution = Restitution;
	PhysMat->Friction = Friction;

	PhysMat->FrictionCombineMode = FrictionCombineMode;
	PhysMat->RestitutionCombineMode = RestitutionCombineMode;

	return PhysMat;
}