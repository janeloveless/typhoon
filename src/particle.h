#pragma once

#include "precision.h"
#include "core.h"

namespace typhoon {
	class Particle {
		protected :
			// fundamental kinematic quantities relative to world frame
			Vector3 position;	// linear displacement 
			Vector3 velocity;	// linear velocity
			Vector3 acceleration;	// linear acceleration

			// properties of the particle
			real damping;		// purely numerical damping, used to
						// counter numerical instability
						
			real inverseMass;	// store inverse mass so that it's
						// easy to avoid setting zero
						// mass and easy to set infinite mass
		
		public :
			void integrate(real duration);	// integrate forward in time
			//void clearAccumulator(); 	// clears all added forces 
	};
}
