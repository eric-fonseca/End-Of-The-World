/* Hanna Doerr - 5/5 */

/// INCLUDES + NAMESPACES
#include "bigTree.h"

/// CONSTRUCTOR DEFINITIONS
bigTree::bigTree(void)
{
}

bigTree::bigTree(MeshManagerSingleton* m_pMeshMngr, std::vector<BoundingObjectClass*> objectsList)
{
	createTree(m_pMeshMngr, objectsList);
	Render(m_pMeshMngr);
}


bigTree::bigTree(bigTree const& other) // is this needed?
{
}

bigTree::~bigTree(void)
{
}

bigTree& bigTree::operator=(bigTree const& other)
{
	return *this;
}


/// PUBLIC FUNCTION DEFINITIONS
/*bigTree* bigTree::getInstance()
{
	// what is the instance?
}*/

void bigTree::destroyInstance()
{}

/*Octants* GetOctant(int octantID)
{}*/

void bigTree::createTree(MeshManagerSingleton* m_pMeshMngr, std::vector<BoundingObjectClass*> objectsList)
{
	vector3 minPos;
	vector3 maxPos;

	//Originally where the console log was

	minPos = objectsList[0]->GetCentroidGlobal() - objectsList[0]->GetHalfWidth();
	maxPos = objectsList[0]->GetCentroidGlobal() + objectsList[0]->GetHalfWidth();

	for(int i = 0; i < objectsList.size(); i++){
		if (minPos.x > objectsList[0]->GetCentroidGlobal().x - (objectsList[0]->GetHalfWidth().x*15.0f)){
			minPos.x = objectsList[0]->GetCentroidGlobal().x - (objectsList[0]->GetHalfWidth().x*15.0f);
		}
		else if (maxPos.x < objectsList[0]->GetCentroidGlobal().x + (objectsList[0]->GetHalfWidth().x*15.0f)){
			maxPos.x = objectsList[0]->GetCentroidGlobal().x + (objectsList[0]->GetHalfWidth().x*15.0f);
		}

		if (minPos.y > objectsList[0]->GetCentroidGlobal().y - (objectsList[0]->GetHalfWidth().y*15.0f)){
			minPos.y = objectsList[0]->GetCentroidGlobal().y - (objectsList[0]->GetHalfWidth().y*15.0f);
		}
		else if (maxPos.y < objectsList[0]->GetCentroidGlobal().y + (objectsList[0]->GetHalfWidth().y*15.0f)){
			maxPos.y = objectsList[0]->GetCentroidGlobal().y + (objectsList[0]->GetHalfWidth().y*15.0f);
		}

		if (minPos.z > objectsList[0]->GetCentroidGlobal().z - (objectsList[0]->GetHalfWidth().z*15.0f)){
			minPos.z = objectsList[0]->GetCentroidGlobal().z - (objectsList[0]->GetHalfWidth().z*15.0f);
		}
		else if (maxPos.z < objectsList[0]->GetCentroidGlobal().z + (objectsList[0]->GetHalfWidth().z*15.0f)){
			maxPos.z = objectsList[0]->GetCentroidGlobal().z + (objectsList[0]->GetHalfWidth().z*15.0f);
		}
		
		//Mercy
		if (minPos.x > objectsList[1]->GetCentroidGlobal().x - (objectsList[1]->GetHalfWidth().x*0.2552f)){
			minPos.x = objectsList[1]->GetCentroidGlobal().x - (objectsList[1]->GetHalfWidth().x*0.2552f);
		}
		else if (maxPos.x < objectsList[1]->GetCentroidGlobal().x + (objectsList[1]->GetHalfWidth().x*0.2552f)){
			maxPos.x = objectsList[1]->GetCentroidGlobal().x + (objectsList[1]->GetHalfWidth().x*0.2552f);
		}

		if (minPos.y > objectsList[1]->GetCentroidGlobal().y - (objectsList[1]->GetHalfWidth().y*0.2552f)){
			minPos.y = objectsList[1]->GetCentroidGlobal().y - (objectsList[1]->GetHalfWidth().y*0.2552f);
		}
		else if (maxPos.y < objectsList[1]->GetCentroidGlobal().y + (objectsList[1]->GetHalfWidth().y*0.2552f)){
			maxPos.y = objectsList[1]->GetCentroidGlobal().y + (objectsList[1]->GetHalfWidth().y*0.2552f);
		}

		if (minPos.z > objectsList[1]->GetCentroidGlobal().z - (objectsList[1]->GetHalfWidth().z*0.2552f)){
			minPos.z = objectsList[1]->GetCentroidGlobal().z - (objectsList[1]->GetHalfWidth().z*0.2552f);
		}
		else if (maxPos.z < objectsList[1]->GetCentroidGlobal().z + (objectsList[1]->GetHalfWidth().z*0.2552f)){
			maxPos.z = objectsList[1]->GetCentroidGlobal().z + (objectsList[1]->GetHalfWidth().z*0.2552f);
		}

		//Venus
		if (minPos.x > objectsList[2]->GetCentroidGlobal().x - (objectsList[2]->GetHalfWidth().x*0.6349f)){
			minPos.x = objectsList[2]->GetCentroidGlobal().x - (objectsList[2]->GetHalfWidth().x*0.6349f);
		}
		else if (maxPos.x < objectsList[2]->GetCentroidGlobal().x + (objectsList[2]->GetHalfWidth().x*0.6349f)){
			maxPos.x = objectsList[2]->GetCentroidGlobal().x + (objectsList[2]->GetHalfWidth().x*0.6349f);
		}

		if (minPos.y > objectsList[2]->GetCentroidGlobal().y - (objectsList[2]->GetHalfWidth().y*0.6349f)){
			minPos.y = objectsList[2]->GetCentroidGlobal().y - (objectsList[2]->GetHalfWidth().y*0.6349f);
		}
		else if (maxPos.y < objectsList[2]->GetCentroidGlobal().y + (objectsList[2]->GetHalfWidth().y*0.6349f)){
			maxPos.y = objectsList[2]->GetCentroidGlobal().y + (objectsList[2]->GetHalfWidth().y*0.6349f);
		}

		if (minPos.z > objectsList[2]->GetCentroidGlobal().z - (objectsList[2]->GetHalfWidth().z*0.6349f)){
			minPos.z = objectsList[2]->GetCentroidGlobal().z - (objectsList[2]->GetHalfWidth().z*0.6349f);
		}
		else if (maxPos.z < objectsList[2]->GetCentroidGlobal().z + (objectsList[2]->GetHalfWidth().z*0.6349f)){
			maxPos.z = objectsList[2]->GetCentroidGlobal().z + (objectsList[2]->GetHalfWidth().z*0.6349f);
		}

		//Earth
		if (minPos.x > objectsList[3]->GetCentroidGlobal().x - (objectsList[3]->GetHalfWidth().x*0.6682f)){
			minPos.x = objectsList[3]->GetCentroidGlobal().x - (objectsList[3]->GetHalfWidth().x*0.6682f);
		}
		else if (maxPos.x < objectsList[3]->GetCentroidGlobal().x + (objectsList[3]->GetHalfWidth().x*0.6682f)){
			maxPos.x = objectsList[3]->GetCentroidGlobal().x + (objectsList[3]->GetHalfWidth().x*0.6682f);
		}

		if (minPos.y > objectsList[3]->GetCentroidGlobal().y - (objectsList[3]->GetHalfWidth().y*0.6682f)){
			minPos.y = objectsList[3]->GetCentroidGlobal().y - (objectsList[3]->GetHalfWidth().y*0.6682f);
		}
		else if (maxPos.y < objectsList[3]->GetCentroidGlobal().y + (objectsList[3]->GetHalfWidth().y*0.6682f)){
			maxPos.y = objectsList[3]->GetCentroidGlobal().y + (objectsList[3]->GetHalfWidth().y*0.6682f);
		}

		if (minPos.z > objectsList[3]->GetCentroidGlobal().z - (objectsList[3]->GetHalfWidth().z*0.6682f)){
			minPos.z = objectsList[3]->GetCentroidGlobal().z - (objectsList[3]->GetHalfWidth().z*0.6682f);
		}
		else if (maxPos.z < objectsList[3]->GetCentroidGlobal().z + (objectsList[3]->GetHalfWidth().z*0.6682f)){
			maxPos.z = objectsList[3]->GetCentroidGlobal().z + (objectsList[3]->GetHalfWidth().z*0.6682f);
		}

		//Mars
		if (minPos.x > objectsList[4]->GetCentroidGlobal().x - (objectsList[4]->GetHalfWidth().x*0.3545f)){
			minPos.x = objectsList[4]->GetCentroidGlobal().x - (objectsList[4]->GetHalfWidth().x*0.3545f);
		}
		else if (maxPos.x < objectsList[4]->GetCentroidGlobal().x + (objectsList[4]->GetHalfWidth().x*0.3545f)){
			maxPos.x = objectsList[4]->GetCentroidGlobal().x + (objectsList[4]->GetHalfWidth().x*0.3545f);
		}

		if (minPos.y > objectsList[4]->GetCentroidGlobal().y - (objectsList[4]->GetHalfWidth().y*0.3545f)){
			minPos.y = objectsList[4]->GetCentroidGlobal().y - (objectsList[4]->GetHalfWidth().y*0.3545f);
		}
		else if (maxPos.y < objectsList[4]->GetCentroidGlobal().y + (objectsList[4]->GetHalfWidth().y*0.3545f)){
			maxPos.y = objectsList[4]->GetCentroidGlobal().y + (objectsList[4]->GetHalfWidth().y*0.3545f);
		}

		if (minPos.z > objectsList[4]->GetCentroidGlobal().z - (objectsList[4]->GetHalfWidth().z*0.3545f)){
			minPos.z = objectsList[4]->GetCentroidGlobal().z - (objectsList[4]->GetHalfWidth().z*0.3545f);
		}
		else if (maxPos.z < objectsList[4]->GetCentroidGlobal().z + (objectsList[4]->GetHalfWidth().z*0.3545f)){
			maxPos.z = objectsList[4]->GetCentroidGlobal().z + (objectsList[4]->GetHalfWidth().z*0.3545f);
		}

		//Jupiter
		if (minPos.x > objectsList[5]->GetCentroidGlobal().x - (objectsList[5]->GetHalfWidth().x*7.4989f)){
			minPos.x = objectsList[5]->GetCentroidGlobal().x - (objectsList[5]->GetHalfWidth().x*7.4989f);
		}
		else if (maxPos.x < objectsList[5]->GetCentroidGlobal().x + (objectsList[5]->GetHalfWidth().x*7.4989f)){
			maxPos.x = objectsList[5]->GetCentroidGlobal().x + (objectsList[5]->GetHalfWidth().x*7.4989f);
		}

		if (minPos.y > objectsList[5]->GetCentroidGlobal().y - (objectsList[5]->GetHalfWidth().y*7.4989f)){
			minPos.y = objectsList[5]->GetCentroidGlobal().y - (objectsList[5]->GetHalfWidth().y*7.4989f);
		}
		else if (maxPos.y < objectsList[5]->GetCentroidGlobal().y + (objectsList[5]->GetHalfWidth().y*7.4989f)){
			maxPos.y = objectsList[5]->GetCentroidGlobal().y + (objectsList[5]->GetHalfWidth().y*7.4989f);
		}

		if (minPos.z > objectsList[5]->GetCentroidGlobal().z - (objectsList[5]->GetHalfWidth().z*7.4989f)){
			minPos.z = objectsList[5]->GetCentroidGlobal().z - (objectsList[5]->GetHalfWidth().z*7.4989f);
		}
		else if (maxPos.z < objectsList[5]->GetCentroidGlobal().z + (objectsList[5]->GetHalfWidth().z*7.4989f)){
			maxPos.z = objectsList[5]->GetCentroidGlobal().z + (objectsList[5]->GetHalfWidth().z*7.4989f);
		}

		//Saturn
		if (minPos.x > objectsList[6]->GetCentroidGlobal().x - (objectsList[6]->GetHalfWidth().x*6.1067f)){
			minPos.x = objectsList[6]->GetCentroidGlobal().x - (objectsList[6]->GetHalfWidth().x*6.1067f);
		}
		else if (maxPos.x < objectsList[6]->GetCentroidGlobal().x + (objectsList[6]->GetHalfWidth().x*6.1067f)){
			maxPos.x = objectsList[6]->GetCentroidGlobal().x + (objectsList[6]->GetHalfWidth().x*6.1067f);
		}

		if (minPos.y > objectsList[6]->GetCentroidGlobal().y - (objectsList[6]->GetHalfWidth().y*6.1067f)){
			minPos.y = objectsList[6]->GetCentroidGlobal().y - (objectsList[6]->GetHalfWidth().y*6.1067f);
		}
		else if (maxPos.y < objectsList[6]->GetCentroidGlobal().y + (objectsList[6]->GetHalfWidth().y*6.1067f)){
			maxPos.y = objectsList[6]->GetCentroidGlobal().y + (objectsList[6]->GetHalfWidth().y*6.1067f);
		}

		if (minPos.z > objectsList[6]->GetCentroidGlobal().z - (objectsList[6]->GetHalfWidth().z*6.1067f)){
			minPos.z = objectsList[6]->GetCentroidGlobal().z - (objectsList[6]->GetHalfWidth().z*6.1067f);
		}
		else if (maxPos.z < objectsList[6]->GetCentroidGlobal().z + (objectsList[6]->GetHalfWidth().z*6.1067f)){
			maxPos.z = objectsList[6]->GetCentroidGlobal().z + (objectsList[6]->GetHalfWidth().z*6.1067f);
		}

		//Uranus
		if (minPos.x > objectsList[7]->GetCentroidGlobal().x - (objectsList[7]->GetHalfWidth().x*2.4618f)){
			minPos.x = objectsList[7]->GetCentroidGlobal().x - (objectsList[7]->GetHalfWidth().x*2.4618f);
		}
		else if (maxPos.x < objectsList[7]->GetCentroidGlobal().x + (objectsList[7]->GetHalfWidth().x*2.4618f)){
			maxPos.x = objectsList[7]->GetCentroidGlobal().x + (objectsList[7]->GetHalfWidth().x*2.4618f);
		}

		if (minPos.y > objectsList[7]->GetCentroidGlobal().y - (objectsList[7]->GetHalfWidth().y*2.4618f)){
			minPos.y = objectsList[7]->GetCentroidGlobal().y - (objectsList[7]->GetHalfWidth().y*2.4618f);
		}
		else if (maxPos.y < objectsList[7]->GetCentroidGlobal().y + (objectsList[7]->GetHalfWidth().y*2.4618f)){
			maxPos.y = objectsList[7]->GetCentroidGlobal().y + (objectsList[7]->GetHalfWidth().y*2.4618f);
		}

		if (minPos.z > objectsList[7]->GetCentroidGlobal().z - (objectsList[7]->GetHalfWidth().z*2.4618f)){
			minPos.z = objectsList[7]->GetCentroidGlobal().z - (objectsList[7]->GetHalfWidth().z*2.4618f);
		}
		else if (maxPos.z < objectsList[7]->GetCentroidGlobal().z + (objectsList[7]->GetHalfWidth().z*2.4618f)){
			maxPos.z = objectsList[7]->GetCentroidGlobal().z + (objectsList[7]->GetHalfWidth().z*2.4618f);
		}

		//Neptune
		if (minPos.x > objectsList[8]->GetCentroidGlobal().x - (objectsList[8]->GetHalfWidth().x*2.3827f)){
			minPos.x = objectsList[8]->GetCentroidGlobal().x - (objectsList[8]->GetHalfWidth().x*2.3827f);
		}
		else if (maxPos.x < objectsList[8]->GetCentroidGlobal().x + (objectsList[8]->GetHalfWidth().x*2.3827f)){
			maxPos.x = objectsList[8]->GetCentroidGlobal().x + (objectsList[8]->GetHalfWidth().x*2.3827f);
		}

		if (minPos.y > objectsList[8]->GetCentroidGlobal().y - (objectsList[8]->GetHalfWidth().y*2.3827f)){
			minPos.y = objectsList[8]->GetCentroidGlobal().y - (objectsList[8]->GetHalfWidth().y*2.3827f);
		}
		else if (maxPos.y < objectsList[8]->GetCentroidGlobal().y + (objectsList[8]->GetHalfWidth().y*2.3827f)){
			maxPos.y = objectsList[8]->GetCentroidGlobal().y + (objectsList[8]->GetHalfWidth().y*2.3827f);
		}

		if (minPos.z > objectsList[8]->GetCentroidGlobal().z - (objectsList[8]->GetHalfWidth().z*2.3827f)){
			minPos.z = objectsList[8]->GetCentroidGlobal().z - (objectsList[8]->GetHalfWidth().z*2.3827f);
		}
		else if (maxPos.z < objectsList[8]->GetCentroidGlobal().z + (objectsList[8]->GetHalfWidth().z*2.3827f)){
			maxPos.z = objectsList[8]->GetCentroidGlobal().z + (objectsList[8]->GetHalfWidth().z*2.3827f);
		}
	}
	
	centroid = (minPos + maxPos) / 2.0f;

	if (octLWH.x < glm::distance(vector3(minPos.x, 0, 0), vector3(maxPos.x, 0, 0))){
		octLWH.x = glm::distance(vector3(minPos.x, 0, 0), vector3(maxPos.x, 0, 0));
	}
	if (octLWH.y < glm::distance(vector3(minPos.y, 0, 0), vector3(maxPos.y, 0, 0))){
		octLWH.y = glm::distance(vector3(minPos.y, 0, 0), vector3(maxPos.y, 0, 0));
	}
	if (octLWH.z < glm::distance(vector3(minPos.z, 0, 0), vector3(maxPos.z, 0, 0))){
		octLWH.z = glm::distance(vector3(minPos.z, 0, 0), vector3(maxPos.z, 0, 0));
	}

	
}

void bigTree::Render(MeshManagerSingleton* m_pMeshMngr)
{
	m_pMeshMngr->AddCubeToQueue(glm::translate(centroid) * glm::scale(vector3(octLWH)), MERED, MERENDER::WIRE);
}

/*void bigTree::InitTree(std::vector<BoundingObjectClass*> boundingObject, int maxSublevels = 4, int maxObjects = 2)
{
}*/

void bigTree::updatePosition(BoundingObjectClass* bObj)
{	
}

/// PRIVATE FUNCTION DEFINITIONS
void bigTree::Release(void)
{}

void bigTree::Init(void)
{}

void bigTree::UpdatePosition(Octants* node, BoundingObjectClass* pBO)
{}

void bigTree::TraverseRender(Octants* node)
{}

void bigTree::TraverseInfo(Octants* node)
{}

void bigTree::TraverseGet(Octants* node, Octants*& output, int octoID)
{}

void bigTree::Subdivide(Octants* node, bool resetCount)
{
   //int* howManyKids = node->children.size();
	//Onode->children->size();
	
	for(int i=0; i < 8; i++)
   {
    if(node->isLeaf && node->children != NULL){
	vector3 minBB;
	vector3 maxBB;
	vector3 avgBB;

	minBB = node->objectsInside[0]->GetCentroidGlobal() - node->objectsInside[0]->GetHalfWidth();
	maxBB = node->objectsInside[0]->GetCentroidGlobal() + node->objectsInside[0]->GetHalfWidth();
	avgBB = (minBB + maxBB)/2.0f;
	   
	//AABB aabb;
	//aabb.minBB.z = minBB.z;
	//aabb.maxBB.z = avgBB.z;
	//aabb.minBB.y = minBB.y;
	//aabb.maxBB.y = avgBB.y;
	//aabb.minBB.x = minBB.x;
	//aabb.maxBB.x = avgBB.x;
	BoundingObjectClass* aabb = node->octBO;
	aabb->m_v3MinAABBG.z = minBB.z;
	aabb->m_v3MaxAABBG.z = avgBB.z;
	aabb->m_v3MinAABBG.y = minBB.y;
	aabb->m_v3MaxAABBG.y = avgBB.y;
	aabb->m_v3MinAABBG.x = minBB.x;
	aabb->m_v3MaxAABBG.x = avgBB.x;
 
	//if(i & 4){ // greater z
		//aabb.minBB.z = avgBB.z;
		//aabb.maxBB.z = maxBB.z;	
	//}
	//if(i & 2){ // greater y
		//aabb.minBB.y = avgBB.y;
		//aabb.maxBB.y = maxBB.y;
	//}
	//if(i & 1){ // greater x
		//aabb.minBB.x = avgBB.x;
		//aabb.maxBB.x = maxBB.x;
	//}
	if(i & 4){ // greater z
		aabb->m_v3MinAABBG.z = avgBB.z;
		aabb->m_v3MaxAABBG.z = maxBB.z;	
	}
	if(i & 2){ // greater y
		aabb->m_v3MinAABBG.y = avgBB.y;
		aabb->m_v3MaxAABBG.y = maxBB.y;	
	}
	if(i & 1){ // greater x
		aabb->m_v3MinAABBG.x = avgBB.x;
		aabb->m_v3MaxAABBG.x = maxBB.x;	
	}

	//node->hasChild = true;
	//node->treeLevel++
	node->Render(); //render
	//what do we do with resetCount?
	   
	}

  }

}



void bigTree::DeleteNode(Octants*& node)
{}