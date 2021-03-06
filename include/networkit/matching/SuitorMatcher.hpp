/*
 *  SuitorMatcher.h
 *
 *  Created on: 27.08.2019
 *  Author: Michal Boron
 */

#ifndef SUITORMATCHER_H_
#define SUITORMATCHER_H_

#include <algorithm>
#include <vector>
#include <unordered_set>

#include <networkit/matching/Matcher.hpp>

namespace NetworKit {

/**
 * @ingroup matching
 * Suitor matching finding algorithm
 */
class SuitorMatcher : public Matcher {
protected:

    // Original suboptimal implementation
    void findSuitorOriginal(node u);
    // Implementation with sorted adjlists
    void findSuitor(node u);
    void matchSuitor(node v);
    void init();

#ifndef NDEBUG
    // Debugging methods
    void checkMatching() const;
    void checkSortedEdges() const;
#endif

public:
    SuitorMatcher(const Graph &G);

    void run() override;

    // Run original suboptimal implementation
    void runOriginal();

    std::vector<node> suitor;
    std::vector<edgeweight> ws;
    std::vector<Graph::NeighborWeightIterator> neighborIterators;
    std::vector<unsigned char> affected;
};

} /* namespace NetworKit */

#endif /* SUITORMATCHER_H_ */