#include "BearPart.h"
#include "Interface/Drawable3D.h"
#include "3D/Primitive/CylinderPrimitive.h"
#include "Texture/TextureMgr.h"
#include "GameNodeEditor.h"
#include "MainMenu.h"

namespace tzw
{
BearPart::BearPart()
{
	m_a = nullptr;
	m_b = nullptr;
	m_isFlipped = false;
	m_node = nullptr;
	auto nodeEditor = MainMenu::shared()->getNodeEditor();
	auto node  = new GameNodeEditorNode();
	node->addIn("active");
	char a[512];
	sprintf(a, "bearPart#%d",this);
	node->name = a;
	nodeEditor->addNode(node);
}

void BearPart::updateFlipped()
{
	if(!m_node) return;
	auto cylinder = static_cast<CylinderPrimitive *>(m_node);
	if(m_isFlipped)
	{
		cylinder->setTopBottomTex(TextureMgr::shared()->getByPath("Texture/bear_flipped.png"));
	}
	else
	{
		cylinder->setTopBottomTex(TextureMgr::shared()->getByPath("Texture/bear.png"));
	}
}
}
