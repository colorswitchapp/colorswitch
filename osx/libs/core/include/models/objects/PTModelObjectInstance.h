#ifndef PTMODELOBJECTINSTANCE_H
#define PTMODELOBJECTINSTANCE_H

#include "PTModelObject.h"
#include "PTModelObjectAsset.h"

class PTModelObjectInstance : public PTModelObject
{
public:
    PTModelObjectInstance( CCString className = "PTModelObjectInstance");
    static PTModel * create() {
        return new PTModelObjectInstance();
    }

    virtual CCDictionary* getConnectionsDictionary();
    virtual void initConnectionsWithDictionary(CCDictionary* dict);

    virtual PTModelObject* duplicated();
    virtual void match(PTModel* model);

    PTModelObjectAsset *referenceModel();
    void setReferenceModel(PTModelObjectAsset* model);

    virtual PTModelSpriteContainer *sprite();

    virtual bool isSpawner();
    virtual float spawnRate();

private:
    PTModelObjectAsset* _referenceModel;
};

#endif // PTMODELOBJECTINSTANCE_H
