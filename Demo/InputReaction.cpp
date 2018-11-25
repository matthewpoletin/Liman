#include "InputReaction.h"

#include "Game.h"

using namespace liman;

ActorId g_currActorId = 5;

void TempInputReaction() {
	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyClicked(GLFW_KEY_1))
		g_currActorId = 1;

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyClicked(GLFW_KEY_2))
		g_currActorId = 2;

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_A)) {
		auto* pTrans = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(
				g_currActorId)->GetComponent<TransformComponent>(TransformComponent::g_Name);
		maths::Vec3f rot = pTrans->GetRot();
		rot.y -= 5.0f;
		pTrans->SetRot(rot.x, rot.y, rot.z);
//		pTrans->SetRot(maths::Vec3f(rot.x, rot.y, rot.z));
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_D)) {
		auto* pTrans = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(
				g_currActorId)->GetComponent<TransformComponent>(TransformComponent::g_Name);
		maths::Vec3f rot = pTrans->GetRot();
		rot.y += 5.0f;
		pTrans->SetRot(rot.x, rot.y, rot.z);
//		pTrans->SetRot(maths::Vec3f(rot.x, rot.y, rot.z));
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_W)) {
		auto* pTrans = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(
				g_currActorId)->GetComponent<TransformComponent>(TransformComponent::g_Name);
		maths::Vec3f rot = pTrans->GetRot();
		rot.x -= 5.0f;
		pTrans->SetRot(rot.x, rot.y, rot.z);
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_S)) {
		auto* pTrans = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(
				g_currActorId)->GetComponent<TransformComponent>(TransformComponent::g_Name);
		maths::Vec3f rot = pTrans->GetRot();
		rot.x += 5.0f;
		pTrans->SetRot(rot.x, rot.y, rot.z);
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_RIGHT)) {
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x + 10, pos.y, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes right");
	}
	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_LEFT)) {
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x - 10, pos.y, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes left");
	}
	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_UP)) {
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y + 10, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes up");
	}
	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_DOWN)) {
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y - 10, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes down");
	}
	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_SPACE)) {
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y, pos.z + 10), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes forward");
	}
	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_LEFT_SHIFT)) {
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y, pos.z - 10), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes backward");
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyPressed(GLFW_KEY_ENTER)) {
		Camera* pCam = g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(0.0f, 0.0f, 600.0f), pCam->GetForward(), pCam->GetUp());
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsKeyClicked(GLFW_KEY_ESCAPE)) {
		g_pApp->GetGraphicsSystem()->GetDisplay()->Close();
		LOG("Game", "Quiting");
	}

	if (g_pApp->GetGameLogic()->GetInputManager()->IsButtonClicked(GLFW_MOUSE_BUTTON_LEFT)) {
		LOG("Player", "Shoots");
	}

	//if (pKeyboard->isKeyPressed(GLFW_KEY_W))
	//{
	//	LOG("Keyboard input", "Key W was pressed");
	//	//OnUpPress();
	//}
	//if (pKeyboard->isKeyPressed(GLFW_KEY_S))
	//{
	//	LOG("Keyboard input", "Key S was pressed");
	//	//OnDownPress();
	//}
	//if (pKeyboard->isKeyPressed(GLFW_KEY_A))
	//{
	//	LOG("Keyboard", "Key A was pressed");
	//	//OnLeftPress();
	//}
	//if (pKeyboard->isKeyPressed(GLFW_KEY_D))
	//{
	//	LOG("Keyboard", "Key D was pressed");
	//	//OnRightPress();
	//}
	//if (pKeyboard->isKeyTyped(GLFW_KEY_SPACE))
	//{
	//	LOG("Keyboard", "Key Space was pressed");
	//	//OnJumpClick();
	//}
}