#include "../SDK/SDK.h"

#include "../Features/Resolver/Resolver.h"

MAKE_HOOK(CTFPlayer_UpdateClientSideAnimation, S::CTFPlayer_UpdateClientSideAnimation(), void,
	void* rcx)
{
	DEBUG_RETURN(CTFPlayer_UpdateClientSideAnimation, rcx);

	auto pPlayer = reinterpret_cast<CTFPlayer*>(rcx);

	const bool bIsLocalPlayer = pPlayer->entindex() == I::EngineClient->GetLocalPlayer()
		&& !I::EngineClient->IsPlayingDemo();

	const bool bSkipAnim = !bIsLocalPlayer
		&& F::Resolver.GetAngles(pPlayer)
		&& !G::UpdatingAnims;

	if (!bSkipAnim)
		CALL_ORIGINAL(rcx);
}