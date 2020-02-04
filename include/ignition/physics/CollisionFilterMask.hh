/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef IGNITION_PHYSICS_COLLISIONFILTERMASK_HH_
#define IGNITION_PHYSICS_COLLISIONFILTERMASK_HH_

#include <ignition/physics/FeatureList.hh>

namespace ignition {
namespace physics {

/////////////////////////////////////////////////
class CollisionFilterMaskFeature : public virtual Feature
{
  public: template <typename PolicyT, typename FeaturesT>
  class Shape : public virtual Feature::Shape<PolicyT, FeaturesT>
  {
    public: void SetCollisionFilterMask(const uint16_t _mask);

    public: uint16_t GetCollisionFilterMask() const;

    public: void RemoveCollisionFilterMask();
  };

  public: template <typename PolicyT>
  class Implementation : public virtual Feature::Implementation<PolicyT>
  {
    public: virtual void SetCollisionFilterMask(
        const Identity &_shapeID, const uint16_t _mask) = 0;

    public: virtual uint16_t GetCollisionFilterMask(
        const Identity &_shapeID) const = 0;

    public: virtual void RemoveCollisionFilterMask(
        const Identity &_shapeID) = 0;
  };
};

}
}

#include <ignition/physics/detail/CollisionFilterMask.hh>

#endif
