#include <assert.h>

#include "particle.h"

using namespace typhoon;

// TODO test the "slow", easier to read, version of this code
/*
 * Integrate the equations of motion using Euler method.
 *
 * Because Euler has numerical stability issues, we introduce a damping factor.
 */
void Particle::integrate(real duration) {
	// don't integrate if particle has infinite mass
	if (inverseMass <= 0.0f) return;

	// duration must be positive -- we are going forward in time!
	assert (duration > 0.0);

	// update position using velocity, using faster version of
	// position = position + velocity*duration;
	position.addScaledVector(velocity, duration);

	// accumulate accelerations (will be added to later)
	Vector3 resultingAcc = acceleration;

	// update velocity using acceleration, using faster version of
	// velocity = velocity + acceleration*duration
	velocity.addScaledVector(acceleration, duration);

	// impose damping to counter numerical instability
	// TODO prove this form is correct!
	velocity *= real_pow(damping, duration);

	// clear the forces
	//clearAccumulator();
}
